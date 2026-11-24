"""Bind a task's decorated names to target RVAs from a compiled candidate object (local only).

`tools/verifier/attempt` calls this after every compile, so a Drafter never runs a separate bind
step; `python3 tools/ghidra/export_pack.py bind --task <dir>` runs the same code by hand.

Compared functions (`task.json` `functions[].symbol`). The decorated name is whatever the
Drafter's declarations produce, so it is found in the object (`resolve_functions`). Each function
is declared under up to two names: its compact header line `// 0x<rva> Class::Method` in the
unit (optionally with the parameter list and cv-qualifier, `// 0x<rva> Class::Method(int) const`)
and its community name. In passes over all functions, so one function never takes another's
exact match by coming first:

1. a hint in `<task dir>/bind-hints.json` whose RVA is the function's RVA, else the current
   symbol if the object still defines it;
2. the definitions whose qualified name (template arguments, return type and parameters
   dropped) equals a declared name; failing that, for `Class::Ctor`, `Class::Class`,
   `Class::dtor` or `Class::~Class`, the class's constructors or destructors (plain, deleting,
   and deleting-destructor adjustor thunks);
3. the definitions whose member name (last component) equals a declared one's, except those
   whose qualified name another compared function declares (an override named for its base).

Several definitions under one name (const and non-const overloads, a static and a member,
overloaded constructors, a destructor and its thunks) are narrowed, each step only when it
leaves at least one: by the header line's declared signature, by the target's size, by the
published target hash (data/target-hashes). Still several is unbound, listing the `// CI hash:`
line that would name each. None of this decides a match: the comparator checks the bound symbol.

Destructors are special. A virtual destructor's vtable slot 0 in the image is the scalar
(`??_G`) or vector (`??_E`) deleting destructor, not the plain `??1` the community name
`X::~X` demangles to, and the compiler emits all of them as separate functions. The task's
`functions[].destructor` (written by `annotate_destructors` from the pack: slot 0, a test of the
delete-flag argument and a call guarded by it) lists the decorated prefixes the target can be.
For such a function steps 2 to 4 are replaced by: the current symbol if its prefix is allowed,
else the one allowed destructor of the class in the object, else, when several are allowed and
defined, the one whose size equals the target's (closest otherwise), reported as a choice.

A hint whose RVA is a compared function's RVA but which does not end up naming it (not defined
in the object, ambiguous, or overridden) is reported as ignored and makes `main` fail; it is
never dropped silently.

A defined function is an external symbol at offset 0 of its own code section, which is what the
comparator requires anyway. When a previously bound symbol is gone and another is found, that is
reported as "decorated name changed" with both names, and the old map entry is removed (a stale
entry at the same RVA would be an undeclared alias).

References (relocations that leave a compared function). Each needs a map entry giving the RVA
the game encodes; in order:

1. a hint naming the symbol (decorated, or qualified as above); it replaces a different entry
   already in `symbols.json`, which is reported;
2. an entry already in `symbols.json`;
3. by position: the target's own relocated field at the same offset, decoded from the local
   image, when that RVA is one of the pack's listed references of this function (so a
   misaligned candidate cannot bind a wrong address: the decoded value must be a known target);
4. the one pack reference whose community name equals the symbol's qualified name, or failing
   that its member name.

The same applies to references made from the function's funclets (catch and unwind code the
comparator compares with it, found through its .pdata, unwind info and FuncInfo). For an unwind
funclet the pack's `object_lifetimes` adds the destructor calls of its state: by position at the
state's funclet RVA when the decoded value is one of them, by community name, or, when the state
lists exactly one call and the funclet leaves exactly one name unbound, that call. A destructor the
compiler generates for a local is often not in the pack at all; a call from an unwind funclet whose
decoded target is a function start of the private function table (`SR_FUNCTION_TABLE`, else
`.local/analysis/functions.jsonl` of the checkout or of the main checkout) binds by position too.

5. a compiler-made literal whose name spells its value (`__real@<hex>`, `__xmm@<hex>`, or a narrow
   string `??_C@_0...`): the address the target's own field holds when the image holds exactly those
   bytes there; else the one address among the pack's references that holds them; else, for a complete
   string only, the one place in the image's data that holds exactly that text (preceded by a NUL).
   The comparator still checks the binding, so a wrong choice fails with relocation-target-mismatch.

Hint keys may be decorated names, qualified names or, for a thread-local or data variable, its bare
member name (`g_tlsErrorContext`) when no other referenced symbol has that member name. A hint that
names no symbol of the object is listed by name as unused; every unbound reference is listed by name
with a ready-to-paste hints object.

Anything left is listed with the file to edit. The comparator still checks every binding: a
wrong RVA fails with relocation-target-mismatch, it cannot pass.

Where the map lives. A task whose `symbols` is the repository map (`reports/<build id>/...`) has
its new entries added through `tools/symbol_map.py`, the only writer of that map, with a
provenance entry saying bind found them. A rename or removal is applied only if it leaves every
match record in the checkout valid (a draft renaming its own function); otherwise bind refuses
and the change needs `tools/symbol_map.py add --allow-change`. A private `symbols.json` is edited
in place as before.

Thread-local variables (references by a SECREL relocation) are never bound by position alone or by
community name. Two things bind one, as a `thread-local` map entry with a TLS-template offset
(docs/comparator-contract.md, "Thread-local variables"): a private hint `"<name>": "tls:0x<offset>"`,
or, with no hint, the offset the unit declares in the variable's own name, `tls_0x<offset>` anywhere
in the member name (`playerState_tls_0x768`). The declared offset is accepted only when the target's
own field at the same position, less the unit's addend, equals it and it lies inside the image's TLS
template; a name that disagrees with the target binds nothing. `_tls_index` needs
no entry; the comparator takes it from the image's TLS directory. A `tls:` hint that no compared
SECREL reference uses is listed under ignored hints. A thread-local entry is published to the
repository map like any other, with a provenance entry giving its offset; because the comparator
checks every thread-local entry against the image's TLS template, adding one makes every match
record pinned to an earlier map version stale, so bind refuses it while such records exist and
the addition needs `tools/symbol_map.py add --allow-change` and re-confirmation of those records.

`bind-hints.json` (private, optional), keys are decorated names (`?...`) or qualified names as
the Drafter wrote them (`BSTimer::QGlobalTimeMultiplier`, `GetArmorKind`), values are RVAs:

    {"?GetArmorKind@@YAHPEAVTESObjectARMO@@@Z": "0x27edf0",
     "BSTimer::QGlobalTimeMultiplier": "0x20ccac8"}

Keys may start with `_` (the CRT's `_Init_thread_epoch`); only a `_` key whose value is neither an
RVA nor a `tls:` value is skipped, as a note. `data/crt-bind-defaults.json` ({build id: {name: value}})
supplies the CRT thread-safe-static symbols of a build as hints of lowest priority, used only when the
object references them; a unit's `// CI hash:` line and a private hint override it.

A hint whose RVA is a compared function's RVA names that function's decorated or qualified name.
Use hints for targets without a community name, template members and renamed stand-ins; give
only RVAs listed in the function's pack (never guessed ones).
"""
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
sys.path.insert(0, str(REPO / 'tools'))
from pecoff import CoffObject, PeImage, Reject, SCN_CNT_CODE, STORAGE_EXTERNAL, SYM_UNDEFINED  # noqa: E402
import symbol_map as symbol_maps  # noqa: E402

UNBOUND = 'unbound:'
HINTS = 'bind-hints.json'
CRT_DEFAULTS = 'data/crt-bind-defaults.json'
# Comparator reasons that mean "nothing was compared because a name is not bound", not a code difference.
BINDING_REASONS = {'function-symbol-missing', 'unresolved-symbol'}
REL32_TAIL = {0x04: 0, 0x05: 1, 0x06: 2, 0x07: 3, 0x08: 4, 0x09: 5}
ADDR32NB = 0x03
SECREL = 0x0B
TLS_HINT = re.compile(r'tls:(0x[0-9a-fA-F]+|[0-9]+)')
TLS_NAME = re.compile(r'(?:^|_)tls_0x([0-9a-fA-F]{1,8})(?:_|$)')
# Resolved by the comparator from the image's TLS directory, so it never gets a map entry.
DIRECTORY_SYMBOLS = {'_tls_index'}
UNDNAME = ('llvm-undname', '/opt/homebrew/opt/llvm/bin/llvm-undname', '/usr/local/opt/llvm/bin/llvm-undname')


def parse_rva(value):
    if isinstance(value, int) and not isinstance(value, bool):
        return value
    if isinstance(value, str) and re.fullmatch(r'0x[0-9a-fA-F]+|[0-9]+', value):
        return int(value, 0)
    raise ValueError(f'not an RVA: {value!r}')


def find_undname(objdump=None):
    """llvm-undname, preferably next to the configured llvm-objdump."""
    names = []
    if objdump:
        names.append(str(Path(objdump).with_name('llvm-undname')))
    for name in names + [os.environ.get('SR_UNDNAME')] + list(UNDNAME):
        if name and (shutil.which(name) or (os.path.isfile(name) and os.access(name, os.X_OK))):
            return shutil.which(name) or name
    return None


def strip_templates(text):
    out, depth = [], 0
    for ch in text:
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth = max(depth - 1, 0)
        elif depth == 0:
            out.append(ch)
    return ''.join(out)


def qualified(demangled):
    """`Scope::member` from a demangled declaration, without template arguments, types or parameters."""
    if not demangled:
        return None
    text = strip_templates(demangled)
    if '(' in text and 'operator' not in text:
        text = text[:text.index('(')]
    tokens = text.replace('*', ' ').replace('&', ' ').split()
    return tokens[-1] if tokens else None


def fallback_qualified(name):
    """Qualified name for plain `?member@Scope@...@@` decorations without a demangler; None otherwise."""
    m = re.match(r'\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)*)@', name)
    if not m:
        return None
    return '::'.join([x for x in reversed(m.group(2).split('@')) if x] + [m.group(1)])


def member(name):
    return name.split('::')[-1] if name else None


def community_qualified(name):
    parts = [p for p in strip_templates(name or '').split('::') if p]
    while parts and parts[0] in ('RE', 'Offset'):
        parts.pop(0)
    return '::'.join(parts) or None


class Names:
    """Qualified names of decorated symbols, demangled with llvm-undname when available."""

    def __init__(self, tool=None):
        self.tool, self.cache, self.text = tool, {}, {}

    def load(self, names):
        todo = [n for n in names if n not in self.cache and n.startswith('?')]
        if todo and self.tool:
            out = subprocess.run([self.tool] + todo, capture_output=True, text=True, timeout=60).stdout
            blocks = [b.split('\n') for b in out.strip().split('\n\n')]
            for block in blocks:
                if len(block) >= 2 and not block[1].startswith('error'):
                    self.cache[block[0]] = qualified(block[1])
                    self.text[block[0]] = block[1]
        for n in names:
            # Undecorated names (extern "C", tests) are their own qualified name; compiler-made
            # names such as __real@ or $unwind$ are never bound by name.
            plain = n if re.fullmatch(r'[A-Za-z_]\w*', n) and not n.startswith('__') else None
            self.cache.setdefault(n, fallback_qualified(n) if n.startswith('?') else plain)

    def __call__(self, name):
        self.load([name])
        return self.cache.get(name)


def defined_functions(obj):
    """{name: section} for external symbols at offset 0 of a code section (comparable functions)."""
    out = {}
    for sym in obj.symbols.values():
        if sym.storage == STORAGE_EXTERNAL and sym.section > 0 and sym.value == 0 \
                and obj.section(sym.section).flags & SCN_CNT_CODE:
            out[sym.name] = sym.section
    return out


def outgoing(obj, section):
    """[(relocation, target symbol)] in `section` whose target lies outside it."""
    sec = obj.section(section)
    out = []
    for rel in sec.relocs:
        target = obj.symbols[rel.symbol]
        if target.section != section:
            out.append((rel, target))
    return out


EH_DATA_SECTIONS = ('.pdata', '.xdata', '.rdata', '.data$r')


def funclets(obj, section, defined_sections):
    """{code section: state or None} of the funclets a function's exception data reaches.

    Starts at the function's own .pdata entries (only the entry whose begin address is in the
    function, so a shared .pdata does not pull in other functions), follows the unwind info, the
    C++ FuncInfo and its maps through data sections, and collects every code section reached that
    is not the function itself and does not define another function. This is the set the
    comparator compares as funclet code, so a reference made only from a funclet is bound too.
    The state is the unwind-map index of an unwind (destructor) funclet when the FH3 map is
    readable, which ties it to the pack's object-lifetime state of the same index.
    """
    group, found = [section], {}
    seen_data = set()
    while group:
        code = group.pop()
        queue = []
        for sec in obj.sections:
            if not sec.name.startswith('.pdata'):
                continue
            starts = {r.offset for r in sec.relocs if obj.symbols[r.symbol].section == code and r.offset % 12 == 0}
            queue += [obj.symbols[r.symbol].section for r in sec.relocs if r.offset - 8 in starts]
        while queue:
            index = queue.pop()
            if index <= 0 or index in seen_data or index == section or index in found:
                continue
            sec = obj.section(index)
            if sec.flags & SCN_CNT_CODE:
                if index not in defined_sections:
                    found[index] = None
                    group.append(index)
                continue
            if not sec.name.startswith(EH_DATA_SECTIONS):
                continue
            seen_data.add(index)
            queue += [obj.symbols[r.symbol].section for r in sec.relocs]
    for state, target in unwind_actions(obj, section):
        if target.section in found:
            found[target.section] = (state, target.value)
    return found


def unwind_actions(obj, section):
    """[(state, funclet symbol)] from the FH3 `$cppxdata$` FuncInfo of the function in `section`."""
    out = []
    for sym in obj.symbols.values():
        if not sym.name.startswith('$cppxdata$') or sym.section <= 0:
            continue
        info = obj.section(sym.section)
        rels = {r.offset: obj.symbols[r.symbol] for r in info.relocs}
        if info.data is None or not _reaches(obj, sym, section):
            continue
        try:
            max_state = struct.unpack_from('<I', info.data, sym.value + 4)[0]
        except struct.error:
            continue
        umap = rels.get(sym.value + 8)
        if umap is None or umap.section <= 0 or max_state > 4096:
            continue
        msec = obj.section(umap.section)
        mrels = {r.offset: obj.symbols[r.symbol] for r in msec.relocs}
        for i in range(max_state):
            action = mrels.get(umap.value + 8 * i + 4)
            if action is not None and action.section > 0:
                out.append((i, action))
    return out


def _reaches(obj, cppxdata, section):
    """Whether the FuncInfo `cppxdata` belongs to the function in `section` (its IP map starts there)."""
    info = obj.section(cppxdata.section)
    rels = {r.offset: obj.symbols[r.symbol] for r in info.relocs}
    ipmap = rels.get(cppxdata.value + 24)
    if ipmap is None or ipmap.section <= 0:
        return False
    return any(obj.symbols[r.symbol].section == section for r in obj.section(ipmap.section).relocs)


def lifetime_calls(repo, fn):
    """{state: [(rva, community qualified name or None)]} of a pack's object-lifetime destructor calls."""
    if not fn.get('pack'):
        return {}, {}
    path = Path(repo) / fn['pack'] / 'pack.json'
    if not path.is_file():
        return {}, {}
    life = json.loads(path.read_text()).get('object_lifetimes') or {}
    calls, places = {}, {}
    for st in life.get('states') or []:
        entries = []
        for text in st.get('calls') or []:
            head, _, rest = str(text).partition(' ')
            try:
                entries.append((parse_rva(head), community_qualified(rest.strip()) if rest.strip() else None))
            except ValueError:
                continue
        calls[st.get('state')] = entries
        if st.get('funclet'):
            places[st.get('state')] = parse_rva(st['funclet'])
    return calls, places


_function_starts = {}


def function_starts(repo):
    """Set of function-start RVAs of the private function table, or None when no table is present."""
    candidates = []
    if os.environ.get('SR_FUNCTION_TABLE'):
        candidates.append(Path(os.environ['SR_FUNCTION_TABLE']))
    candidates.append(Path(repo) / '.local/analysis/functions.jsonl')
    try:
        out = subprocess.run(['git', 'rev-parse', '--path-format=absolute', '--git-common-dir'], cwd=repo,
                             capture_output=True, text=True)
        if out.returncode == 0 and out.stdout.strip():
            candidates.append(Path(out.stdout.strip()).parent / '.local/analysis/functions.jsonl')
    except OSError:
        pass
    # The intake tree is a clone under the main checkout's .local, so its own .local holds no tables.
    candidates += [d / '.local/analysis/functions.jsonl' for d in Path(repo).resolve().parents]
    for path in candidates:
        if not path.is_file():
            continue
        key = (str(path), path.stat().st_mtime_ns)
        if key not in _function_starts:
            starts = set()
            with open(path) as fh:
                for line in fh:
                    if line.strip():
                        starts.add(json.loads(line)['rva'])
            _function_starts[key] = starts
        return _function_starts[key]
    return None


def declared_tls_offset(name):
    """The TLS-template offset a variable's member name declares as `tls_0x<offset>`, or None."""
    m = TLS_NAME.search(name or '')
    return int(m.group(1), 16) if m else None


def by_position(image, fn_rva, rel):
    """The RVA the target's own field at the relocation's offset encodes, or None."""
    if image is None:
        return None
    try:
        field = image.read(fn_rva + rel.offset, 4, 'bind')[1]
    except Exception:
        return None
    if rel.kind in REL32_TAIL:
        (disp,) = struct.unpack('<i', field)
        return fn_rva + rel.offset + 4 + REL32_TAIL[rel.kind] + disp
    if rel.kind == ADDR32NB:
        return struct.unpack('<I', field)[0]
    return None


POOL_CONSTANT = re.compile(r'__(?:real|xmm)@([0-9a-fA-F]+)\Z')


def pool_constant_bytes(name):
    """The bytes a compiler-made `__real@<hex>` / `__xmm@<hex>` constant holds (little-endian value), or None."""
    m = POOL_CONSTANT.fullmatch(name or '')
    if not m or len(m.group(1)) not in (8, 16, 32):
        return None
    return int(m.group(1), 16).to_bytes(len(m.group(1)) // 2, 'little')


STRING_LITERAL = re.compile(r'\?\?_C@_0(?:([0-9])|([A-P]+)@)[0-9A-Z]{8}@(.*)@\Z')
LITERAL_ESCAPES = dict(zip('0123456789', ',/\\:. \n\t\'-'))


def string_literal_bytes(name):
    """(bytes, complete) a narrow string literal's decorated name spells, or None.

    `??_C@_0<length><hash>@<text>@`: the length counts the terminating NUL; 1 to 10 is one digit 0 to 9,
    anything longer is base 16 with digits A to P ended by `@`; the text is spelled out for the first 32
    characters (`?<digit>` for punctuation, `?<letter>` for lower case, `?$<two letters>` for any other
    byte). `complete` is False when the literal is longer than what the name spells.
    """
    m = STRING_LITERAL.fullmatch(name or '')
    if not m:
        return None
    single, letters, text = m.groups()
    length = int(single) + 1 if single else int(''.join(format(ord(c) - ord('A'), 'x') for c in letters), 16)
    out, i = bytearray(), 0
    while i < len(text):
        c = text[i]
        if c != '?':
            out.append(ord(c))
            i += 1
        elif text[i + 1:i + 2] == '$' and i + 4 <= len(text):
            hi, lo = ord(text[i + 2]) - ord('A'), ord(text[i + 3]) - ord('A')
            if not (0 <= hi < 16 and 0 <= lo < 16):
                return None
            out.append(hi * 16 + lo)
            i += 4
        elif text[i + 1:i + 2] in LITERAL_ESCAPES:
            out.append(ord(LITERAL_ESCAPES[text[i + 1]]))
            i += 2
        elif text[i + 1:i + 2].isalpha() and text[i + 1].isupper():
            out.append(ord(text[i + 1].lower()))
            i += 2
        else:
            return None
    if len(out) + 1 == length:
        return bytes(out) + b'\0', True
    return (bytes(out), False) if len(out) == 32 and length > 33 else None


def find_literal(image, want):
    """RVAs where the image holds exactly the string `want` (NUL-terminated, preceded by a NUL), in the
    sections that are not code; a short or unterminated value is too ambiguous to search for."""
    if not want.endswith(b'\0') or len(want) < 6:
        return []
    out = []
    for sec in image.sections:
        if sec.flags & 0x20000000 or not sec.raw_size:  # IMAGE_SCN_MEM_EXECUTE
            continue
        data = image.blob[sec.raw_ptr:sec.raw_ptr + sec.raw_size]
        at = data.find(want)
        while at != -1:
            if at > 0 and data[at - 1] == 0:
                out.append(sec.vaddr + at)
            at = data.find(want, at + 1)
    return out


def constant_at(image, rva, want):
    """True when the image holds exactly `want` at `rva`."""
    try:
        return image.read(rva, len(want), 'bind')[1] == want
    except Exception:  # noqa: BLE001 - an unreadable address is simply no evidence
        return False


def field_addend(obj, section, rel):
    """The addend the candidate object stores in a relocation's field (a member offset into a global), or 0."""
    if rel.kind not in REL32_TAIL and rel.kind != ADDR32NB:
        return 0
    data = obj.section(section).data
    fmt = '<I' if rel.kind == ADDR32NB else '<i'
    try:
        return struct.unpack_from(fmt, data, rel.offset)[0]
    except struct.error:
        return 0


# MSVC special-name prefixes of the three destructor functions a class with a virtual destructor gets.
DTOR_KINDS = {'??1': 'destructor', '??_G': 'scalar deleting destructor', '??_E': 'vector deleting destructor'}
# Access codes of adjustor thunks (`[thunk]: ... adjustor{n}'`): a thunk is never the slot body itself.
THUNK_ACCESS = set('GHOPWX')
VOLATILE = {'A', 'C', 'D', 'R8', 'R9', 'R10', 'R11'}
WRITES = {'MOV', 'LEA', 'MOVZX', 'MOVSX', 'MOVSXD', 'XOR', 'SUB', 'ADD', 'OR', 'SHL', 'SHR', 'SAR', 'IMUL', 'POP',
          'CMOVZ', 'CMOVNZ', 'CMOVE', 'CMOVNE', 'SETZ', 'SETNZ', 'XCHG'}


def dtor_decoration(name):
    """(prefix, class) of a plain or deleting destructor's decorated name; None for others and thunks.

    Template class scopes (`?$...`) are not parsed; such destructors bind by the ordinary rules.
    """
    for prefix in ('??_G', '??_E', '??1'):
        if not name.startswith(prefix):
            continue
        rest = name[len(prefix):]
        if '@@' not in rest or rest.startswith('?'):
            return None
        scope, tail = rest.split('@@', 1)
        if not scope or not tail or tail[0] in THUNK_ACCESS or '?' in scope:
            return None
        return prefix, '::'.join(reversed(scope.split('@')))
    return None


SPECIAL_KINDS = {'ctor': '??0', 'constructor': '??0', 'dtor': '??1', 'destructor': '??1'}


def special_decoration(name):
    """(prefix, class) of a plain constructor or destructor decoration (`??0`, `??1`, `??_G`, `??_E`).

    Unlike `dtor_decoration` this includes constructors; template scopes and thunks yield None.
    """
    if name.startswith('??0'):
        rest = name[3:]
        if '@@' not in rest or rest.startswith('?'):
            return None
        scope, tail = rest.split('@@', 1)
        if not scope or not tail or tail[0] in THUNK_ACCESS or '?' in scope:
            return None
        return '??0', '::'.join(reversed(scope.split('@')))
    return dtor_decoration(name)


def special_kind(cls, last):
    """Decoration prefixes a `Class::<last>` community name denotes, or None when it is no ctor/dtor name."""
    base = cls.split('::')[-1]
    key = last.lower()
    if key in SPECIAL_KINDS:
        return (SPECIAL_KINDS[key],) if SPECIAL_KINDS[key] == '??0' else ('??1', '??_G', '??_E')
    if last == base:
        return ('??0',)
    if last == '~' + base:
        return ('??1', '??_G', '??_E')
    return None


def class_special_candidates(community, defined, taken):
    """Definitions whose decorated name is the constructor/destructor of the community name's class.

    Several classes' constructors can share one object (a base member's, a helper type's), so
    a name that is only `Class::Ctor` must be narrowed by the decorated class, not by the last
    component. Returns None when the community name is not of that form.
    """
    if not community or '::' not in community:
        return None
    cls, last = community.rsplit('::', 1)
    kinds = special_kind(cls, last)
    if kinds is None:
        return None
    hits = []
    for d in defined:
        dec = special_decoration(d)
        if d not in taken and dec and dec[0] in kinds and (dec[1] == cls or member(dec[1]) == member(cls)):
            hits.append(d)
    return sorted(hits)


def dtor_thunk_decoration(name):
    """(prefix, class) of an adjustor thunk of a deleting destructor (`??_G<class>@@W<n>...`), else None.

    A class with several bases gets one such thunk per secondary vftable; its slot 0 in the image is
    the thunk, so a `Class::~Class` or `Class::dtor` target can be one.
    """
    for prefix in ('??_G', '??_E'):
        if not name.startswith(prefix):
            continue
        rest = name[len(prefix):]
        if '@@' not in rest or rest.startswith('?'):
            return None
        scope, tail = rest.split('@@', 1)
        if not scope or not tail or tail[0] not in THUNK_ACCESS or '?' in scope:
            return None
        return prefix, '::'.join(reversed(scope.split('@')))
    return None


# Access codes of non-static member functions (private, protected, public; plain and virtual).
# After them a member decoration has `E` (__ptr64) and one cv code for `this`.
MEMBER_ACCESS = set('ABEFIJMNQRUV')
STATIC_ACCESS = set('CDKLST')
CV_CODES = {'A': '', 'B': 'const', 'C': 'volatile', 'D': 'const volatile'}
# The compact source header line: `// 0x<rva> Class::Method`, optionally followed by the
# declaration's parameter list and cv-qualifier, `// 0x<rva> Class::Method(int) const`.
HEADER_LINE = re.compile(r'//[ \t]*0x([0-9a-fA-F]+)[ \t]+([A-Za-z_~][\w:~<>,]*)'
                         r'(?:[ \t]*(\([^)]*\))[ \t]*((?:const|volatile)(?:[ \t]+(?:const|volatile))?)?)?[ \t]*$')


def decoration_traits(name, text=None):
    """{'static', 'cv', 'params'} of a member-function decoration; params only with demangled text.

    The decoration itself gives static-ness and the cv-qualifier of `this` for plain (non-template)
    scopes; the demangled text, when llvm-undname is present, adds the parameter list.
    """
    traits = {'static': None, 'cv': None, 'params': None}
    m = re.match(r'\?(?:\?[0-9A-Z]|\?_[0-9A-Z]|[A-Za-z_]\w*@)((?:[A-Za-z_]\w*@)*)@([A-Z])(E?)([A-D])?', name)
    if m:
        access = m.group(2)
        if access in STATIC_ACCESS or access in ('Y', 'Z'):
            traits['static'] = True
            traits['cv'] = ''
        elif access in MEMBER_ACCESS and m.group(3) == 'E' and m.group(4):
            traits['static'] = False
            traits['cv'] = CV_CODES[m.group(4)]
    if text:
        if traits['cv'] is None:
            tail = text.rsplit(')', 1)[-1].strip() if ')' in text else ''
            traits['cv'] = ' '.join(w for w in tail.split() if w in ('const', 'volatile'))
        depth, start = 0, None
        head = text.split('`', 1)[0]
        for i, ch in enumerate(head):
            if ch == '(' and depth == 0 and start is None:
                start = i
            if ch == '(':
                depth += 1
            elif ch == ')':
                depth -= 1
                if depth == 0 and start is not None:
                    traits['params'] = normalize_params(head[start + 1:i])
                    break
    return traits


FIXED_WIDTH = {'int8_t': 'signedchar', 'uint8_t': 'unsignedchar', 'int16_t': 'short', 'uint16_t': 'unsignedshort',
               'int32_t': 'int', 'uint32_t': 'unsignedint', 'int64_t': '__int64', 'uint64_t': 'unsigned__int64'}


def split_params(text):
    """Top-level comma-separated parts of a parameter list (commas inside <> or () stay)."""
    parts, depth, start = [], 0, 0
    for i, ch in enumerate(text):
        if ch in '<(':
            depth += 1
        elif ch in '>)':
            depth -= 1
        elif ch == ',' and depth == 0:
            parts.append(text[start:i])
            start = i + 1
    parts.append(text[start:])
    return parts


def east_const(param):
    """One parameter with leading cv-qualifiers moved behind the base type, as the demangler prints them.

    A source line says `const T&`; the demangled symbol says `T const &`. Both must compare equal.
    """
    m = re.match(r'((?:(?:const|volatile)\s+)+)(.*)$', param.strip(), re.S)
    if not m:
        return param
    quals, rest = ' '.join(sorted(m.group(1).split())), m.group(2)
    depth = 0
    for i, ch in enumerate(rest):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch in '*&' and depth == 0:
            return f'{rest[:i].strip()} {quals} {rest[i:]}'
    return f'{rest.strip()} {quals}'


def normalize_params(text):
    """Comparable parameter list: elaborated-type keywords, `__ptr64`, spaces and `void` removed.

    Fixed-width integer names read as the builtin the demangler prints, and a leading `const` reads
    as the trailing form, so a source-style line equals the decorated symbol's own parameters.
    """
    text = re.sub(r'\b(class|struct|union|enum|__ptr64|RE::)\b|\bRE::', '', text or '')
    text = re.sub(r'\b(?:std::)?(u?int(?:8|16|32|64)_t)\b', lambda m: ' ' + FIXED_WIDTH[m.group(1)] + ' ', text)
    text = ','.join(east_const(p) for p in split_params(text))
    text = re.sub(r'\s+', '', text)
    return '' if text == 'void' else text


def header_declarations(repo, unit):
    """{rva: declaration} from the leading compact `// 0x<rva> Name[(params)][ const]` lines of a unit.

    The unit's own header is its statement of which definition each compared RVA is, so a
    stand-in named differently from the community map (a slot-number virtual, a renamed static)
    still binds by name. Lines of the .cpp come before those of its .h.
    """
    out = {}
    if not unit:
        return out
    from rva_headers import leading_lines
    base = Path(repo) / unit
    for path in (base.with_suffix('.cpp'), base.with_suffix('.h')):
        if not path.is_file():
            continue
        for line in leading_lines(path.read_text(encoding='utf-8-sig', errors='replace')):
            m = HEADER_LINE.match(line.rstrip())
            if not m:
                continue
            decl = {'name': community_qualified(m.group(2)), 'params': None, 'cv': None}
            if m.group(3) is not None:
                decl['params'] = normalize_params(m.group(3)[1:-1])
                decl['cv'] = ' '.join((m.group(4) or '').split())
            out.setdefault(int(m.group(1), 16), decl)
    return out


def fits_declaration(traits, decl):
    """Whether a definition's traits agree with what a header line declares (unknowns agree)."""
    if not decl or decl.get('params') is None:
        return True
    if traits['cv'] is not None and traits['cv'] != decl['cv']:
        return False
    if traits['params'] is not None and traits['params'] != decl['params']:
        return False
    return True


def target_matcher(repo, blob):
    """callable(rva, symbol) -> bool | None: whether the object's function equals the published target hash.

    It answers None when no current manifest is readable (a stale or partial checkout), so binding
    then never narrows by hash. This only picks among definitions that already carry the right name; the
    comparator still decides the match.
    """
    loaded = {}

    def rows():
        # Read on first use: most binds never need a hash to tell two definitions apart.
        if 'rows' not in loaded:
            try:
                import target_hashes
                manifest = target_hashes.load_manifest(Path(repo))
                loaded['rows'] = {row['rva']: row for row in manifest['functions']}
                loaded['module'] = target_hashes
            except Exception:
                loaded['rows'] = None
        return loaded['rows']

    def match(rva, symbol):
        row = (rows() or {}).get(rva)
        if row is None:
            return None
        try:
            return loaded['module'].candidate(blob, symbol, row) == 'hash-match'
        except Exception:
            return None
    return match


def narrow(candidates, fn, decl, traits_of, size_of, matcher):
    """(remaining candidates, [steps that removed some]) for one function among same-named definitions.

    Each step keeps only the candidates that agree and is skipped when none would: the declared
    signature of the unit's header line, the target's size, the published target hash.
    """
    steps = []
    cands = list(candidates)

    def apply(label, keep):
        nonlocal cands
        kept = [c for c in cands if keep(c)]
        if kept and len(kept) < len(cands):
            cands = kept
            steps.append(label)
    if len(cands) > 1 and decl and decl.get('params') is not None:
        apply('declared signature', lambda c: fits_declaration(traits_of(c), decl))
    if len(cands) > 1:
        size = parse_rva(fn['size'])
        apply('size', lambda c: size_of(c) == size)
    if len(cands) > 1 and matcher is not None:
        rva = parse_rva(fn['rva'])
        apply('target hash', lambda c: matcher(rva, c) is True)
    return cands, steps


def hint_lines(rva, candidates):
    """The `// CI hash:` lines a unit header can carry to name one of several candidates."""
    return [f'// CI hash: {rva} {c}' for c in candidates]


def reg_family(op):
    """Architectural register of an operand (`EBX` -> `B`, `R8D` -> `R8`), or None for memory/immediates."""
    op = op.strip().upper()
    m = re.fullmatch(r'R(8|9|1[0-5])[DWB]?', op)
    if m:
        return 'R' + m.group(1)
    m = re.fullmatch(r'[RE]?([ABCD])X|([ABCD])L', op)
    if m:
        return m.group(1) or m.group(2)
    m = re.fullmatch(r'[RE]?(SI|DI|BP|SP)L?', op)
    return m.group(1) if m else None


def listing_instructions(text):
    """[(mnemonic, [operands])] from a pack listing (`  +0x01a  MOV EBX,EDX   [annotation]`)."""
    out = []
    for line in text.splitlines():
        m = re.match(r'\s*\+0x[0-9a-fA-F]+\s+(\S.*)$', line)
        if not m:
            continue
        insn = re.split(r'\s{2,}', m.group(1).strip())[0]
        mnem, _, ops = insn.partition(' ')
        out.append((mnem.upper(), [o.strip() for o in ops.split(',')] if ops.strip() else []))
    return out


def delete_flag_use(text):
    """(bits of the second argument that are tested, whether a call or jump follows the first test).

    Follows the x64 second argument (EDX) through register copies until it is overwritten or a
    call clobbers it, which is how a deleting destructor keeps its flag across the inlined body.
    """
    flag, bits, called = {'D'}, set(), False
    for mnem, ops in listing_instructions(text):
        if mnem in ('TEST', 'AND', 'BT') and len(ops) == 2 and reg_family(ops[0]) in flag:
            try:
                imm = int(ops[1], 0)
            except ValueError:
                imm = None
            if imm is not None:
                if mnem == 'BT':
                    imm = 1 << imm
                bits |= {b for b in (1, 2) if imm & b}
                continue
        if mnem == 'CALL' or (mnem == 'JMP' and ops and ops[0].startswith('0x')):
            called = called or bool(bits)
            flag -= VOLATILE
            continue
        if not ops:
            continue
        dst = reg_family(ops[0])
        src = reg_family(ops[1]) if len(ops) == 2 else None
        if dst is None:
            continue
        if mnem == 'MOV' and src in flag:
            flag.add(dst)
        elif dst in flag and mnem in WRITES:
            flag.discard(dst)
    return bits, called


def destructor_spec(community_name, name_how, listing):
    """Which destructor functions a target can be, with the evidence; None when it is not a destructor."""
    name = member(community_qualified(community_name)) or ''
    slot0 = (name_how or '').strip() == 'slot 0'
    if not name.startswith('~') and not slot0:
        return None
    bits, called = delete_flag_use(listing) if listing is not None else (set(), False)

    def spec(prefixes, evidence, decided):
        return {'symbols': list(prefixes), 'kind': ' or '.join(DTOR_KINDS[p] for p in prefixes),
                'decided': decided, 'evidence': evidence}
    if 2 in bits:
        return spec(['??_E'], 'tests bit 1 (array delete) of the flag argument', True)
    if bits and called:
        return spec(['??_G'], 'tests bit 0 of the flag argument and calls operator delete under it', True)
    if not name.startswith('~'):
        return None
    if bits:
        return spec(['??_G', '??_E'], 'tests the flag argument but no call follows', False)
    if listing is not None and not slot0:
        return spec(['??1'], 'no delete-flag test and not a vtable slot 0', True)
    return spec(['??_G', '??_E', '??1'], ('vtable slot 0 ' if slot0 else '')
                + ('without a delete-flag test' if listing is not None else 'and no listing in the pack'), False)


def annotate_destructors(task, repo=REPO):
    """Set or clear `destructor` on each compared function from its pack; True when anything changed."""
    changed = False
    for fn in task['functions']:
        if fn.get('role') == 'regression' or not fn.get('pack'):
            continue
        pack = Path(repo) / fn['pack']
        try:
            ident = json.loads((pack / 'pack.json').read_text()).get('identity', {})
        except (OSError, ValueError):
            continue
        listing = (pack / 'listing.txt').read_text() if (pack / 'listing.txt').is_file() else None
        spec = destructor_spec(fn.get('community_name'), ident.get('name_how'), listing)
        if spec != fn.get('destructor'):
            if spec is None:
                fn.pop('destructor', None)
            else:
                fn['destructor'] = spec
            changed = True
    return changed


def _raw_hints(task_dir):
    path = Path(task_dir) / HINTS
    if not path.is_file():
        return {}
    raw = json.loads(path.read_text())
    if not isinstance(raw, dict):
        raise ValueError(f'{path}: must be a JSON object of name -> RVA')
    return {str(k): v for k, v in raw.items() if not _is_note(k, v)}


def _is_note(key, value):
    """A `_`-prefixed key whose value is no RVA and no `tls:` value is a free-text note, not a hint.

    CRT symbols (`_Init_thread_epoch`, `_Init_thread_abort`) start with `_` too, so the prefix alone
    cannot tell the two apart; the value can.
    """
    if not str(key).startswith('_'):
        return False
    if isinstance(value, str) and value.startswith('tls:'):
        return False
    try:
        parse_rva(value)
    except ValueError:
        return True
    return False


def split_hints(raw):
    """(name -> RVA, name -> TLS-template offset) from hint pairs; `tls:0x<offset>` values are offsets."""
    rvas, tls = {}, {}
    for k, v in raw.items():
        if isinstance(v, str) and v.startswith('tls:'):
            m = TLS_HINT.fullmatch(v)
            if not m:
                raise ValueError(f'not a thread-local offset: {v!r}')
            tls[k] = int(m.group(1), 0)
        else:
            rvas[k] = parse_rva(v)
    return rvas, tls


def load_hints(task_dir):
    """name -> RVA hints; `tls:` values are thread-local offsets and are read by load_tls_hints."""
    return split_hints(_raw_hints(task_dir))[0]


def load_tls_hints(task_dir):
    """name -> TLS-template offset from hints of the form "tls:0x<offset>"."""
    return split_hints(_raw_hints(task_dir))[1]


def crt_defaults(repo, build_id):
    """Hints for the CRT's thread-safe-static support symbols in this build, from data/crt-bind-defaults.json.

    Their addresses are properties of the image (the CRT is linked in), not of any unit, and none has
    a community name, so without defaults every unit with a function-local static would need the
    same private hints on every host. Same value forms as bind-hints.json.
    """
    path = Path(repo) / CRT_DEFAULTS
    if not build_id or not path.is_file():
        return {}
    table = json.loads(path.read_text()).get(build_id) or {}
    return {str(k): v for k, v in table.items() if not _is_note(k, v)}


CI_HASH_LINE = re.compile(r'^// CI hash: (0x[0-9a-fA-F]+)[ \t]+(\S+)[ \t]*$', re.M)


def unit_hints(repo, task):
    """{decorated symbol: rva} from the unit's `// CI hash:` lines for its compared RVAs.

    The same lines the CI hash job and the PR bot read (first 8192 bytes), so one statement in the
    source names a definition on every host; a private bind-hints.json entry overrides it.
    """
    unit = task.get('compiled')
    path = Path(repo) / unit if unit else None
    if not path or not path.is_file():
        return {}
    rvas = {parse_rva(f['rva']) for f in task['functions']}
    text = path.read_text(encoding='utf-8-sig', errors='replace')[:8192]
    return {sym: int(rva, 16) for rva, sym in CI_HASH_LINE.findall(text) if int(rva, 16) in rvas}


def pack_references(repo, fn):
    """[(target rva, [community qualified names])] of a function's pack, or []."""
    if not fn.get('pack'):
        return []
    path = Path(repo) / fn['pack'] / 'pack.json'
    if not path.is_file():
        return []
    out = []
    for r in json.loads(path.read_text()).get('references', []):
        names = [community_qualified(c['name']) for c in r.get('community_names', [])
                 if c.get('kind') not in ('vtable', 'rtti', 'nirtti')]
        out.append((r['target_rva'], [n for n in names if n]))
    return out


def resolve_functions(task, defined, names, hints, size_of, matcher=None, header=None):
    """{rva: result} binding each compared function to one definition of the object (no I/O).

    A result is {'symbol', 'how', 'candidates', 'warnings', 'choice'}; `symbol` is None when the
    function stays unbound, and `candidates` then lists the same-named definitions left.

    Passes, so one function can never take another's exact match because it comes first in the
    task: (0) hints and kept symbols; (1) the names each function declares, from the unit header
    line and the community name, matched against parsed qualified names, constructor/destructor
    kinds and the pack's destructor evidence; (2) the member name alone, skipping definitions whose
    qualified name another compared function declares. Where several definitions share the name,
    `narrow` picks by declared signature, then size, then published target hash.
    """
    header = header or {}
    results, taken = {}, set()
    fns = [fn for fn in task['functions']]

    def result(symbol, how, candidates=(), choice=None):
        return {'symbol': symbol, 'how': how, 'candidates': list(candidates), 'warnings': [], 'choice': choice}

    def declared(fn):
        """The qualified names a function is declared under: its header line, then its community name."""
        out = []
        decl = header.get(parse_rva(fn['rva']))
        for n in ((decl or {}).get('name'), community_qualified(fn.get('community_name'))):
            if n and n not in out:
                out.append(n)
        return out

    def traits_of(d):
        return decoration_traits(d, names.text.get(d))

    # Pass 0: an explicit hint for the RVA, else the symbol the task already names.
    for fn in fns:
        rva = parse_rva(fn['rva'])
        spec = fn.get('destructor')
        community = community_qualified(fn.get('community_name'))
        cls = community.rsplit('::', 1)[0] if community and '::' in community else None
        for h in [n for n, r in hints.items() if r == rva]:
            hits = [d for d in defined if d == h or names(d) == h]
            if len(hits) == 1:
                res = result(hits[0], 'hint')
                dec = dtor_decoration(hits[0]) or dtor_thunk_decoration(hits[0])
                if spec and not (dec and dec[0] in spec['symbols'] and cls
                                 and (dec[1] == cls or member(dec[1]) == member(cls))):
                    res['warnings'].append(f'hint {h} for {hex(rva)} overrides the pack evidence for a '
                                           f'{spec["kind"]} ({spec["evidence"]})')
                results[fn['rva']] = res
                taken.add(hits[0])
                break
    for fn in fns:
        if fn['rva'] in results:
            continue
        old = fn.get('symbol') or ''
        spec = fn.get('destructor')
        if old in defined and old not in taken:
            if spec is None or destructor_fits(old, spec, fn):
                results[fn['rva']] = result(old, 'kept')
                taken.add(old)

    # Pass 1: definitions whose parsed name is one the function declares.
    exact_names = {}
    for fn in fns:
        for n in declared(fn):
            exact_names.setdefault(n, set()).add(fn['rva'])
    for fn in fns:
        if fn['rva'] in results:
            continue
        rva = parse_rva(fn['rva'])
        decl = header.get(rva)
        spec = fn.get('destructor')
        if spec is not None:
            results[fn['rva']] = resolve_destructor(fn, spec, defined, taken, size_of, matcher)
            if results[fn['rva']]['symbol']:
                taken.add(results[fn['rva']]['symbol'])
            continue
        # A literal `X::Ctor` member the unit defines is the name itself; only without one does the
        # name denote the class's constructor or destructor.
        # `X::~X` demangles from the plain destructor only, but names all three destructor
        # functions (plain, scalar and vector deleting), so it never counts as an exact match.
        hits = []
        for n in declared(fn):
            if not is_destructor_name(n):
                hits += [d for d in defined if d not in taken and d not in hits and names(d) == n]
        if not hits:
            for n in declared(fn):
                hits += [d for d in (class_special_candidates(n, defined, taken) or []) if d not in hits]
                hits += [d for d in class_thunk_candidates(n, defined, taken) if d not in hits]
        if not hits:
            continue
        cands, steps = narrow(sorted(hits), fn, decl, traits_of, size_of, matcher)
        if len(cands) == 1 and (len(hits) == 1 or steps):
            q = names(cands[0])
            how = ('header name' if decl and q == decl.get('name') and q != community_qualified(fn.get('community_name'))
                   else 'community name' if q in declared(fn) else 'class constructor/destructor name')
            if steps:
                how += ', narrowed by ' + ', '.join(steps)
            results[fn['rva']] = result(cands[0], how)
            taken.add(cands[0])
        else:
            results[fn['rva']] = result(None, None, cands)

    # Pass 2: the member name alone (a virtual override named for its base, a static moved to
    # another class), never a definition whose exact name another compared function declares.
    for fn in fns:
        if fn['rva'] in results:
            continue
        rva = parse_rva(fn['rva'])
        mine = declared(fn)
        hits = []
        for n in mine:
            hits += [d for d in defined if d not in taken and d not in hits and names(d)
                     and member(names(d)) == member(n)
                     and not (exact_names.get(names(d), set()) - {fn['rva']})]
        if not hits:
            results[fn['rva']] = result(None, None)
            continue
        cands, steps = narrow(sorted(hits), fn, header.get(rva), traits_of, size_of, matcher)
        if len(cands) == 1 and (len(hits) == 1 or steps):
            results[fn['rva']] = result(cands[0], 'member name' if len(hits) == 1
                                        else 'member name, narrowed by ' + ', '.join(steps))
            taken.add(cands[0])
        else:
            results[fn['rva']] = result(None, None, cands)
    return results


def is_destructor_name(name):
    if not name or '::' not in name:
        return False
    cls, last = name.rsplit('::', 1)
    kinds = special_kind(cls, last)
    return bool(kinds) and '??0' not in kinds


def destructor_fits(d, spec, fn):
    community = community_qualified(fn.get('community_name'))
    cls = community.rsplit('::', 1)[0] if community and '::' in community else None
    dec = dtor_decoration(d)
    return bool(dec and dec[0] in spec['symbols'] and cls and (dec[1] == cls or member(dec[1]) == member(cls)))


def class_thunk_candidates(name, defined, taken):
    """Deleting-destructor adjustor thunks of the class a `Class::dtor`/`Class::~Class` name denotes."""
    if not name or '::' not in name:
        return []
    cls, last = name.rsplit('::', 1)
    kinds = special_kind(cls, last)
    if not kinds or '??0' in kinds:
        return []
    hits = []
    for d in defined:
        dec = dtor_thunk_decoration(d)
        if d not in taken and dec and (dec[1] == cls or member(dec[1]) == member(cls)):
            hits.append(d)
    return sorted(hits)


def resolve_destructor(fn, spec, defined, taken, size_of, matcher):
    """One function the pack's evidence says is a destructor: plain, deleting, or a deleting thunk."""
    community = community_qualified(fn.get('community_name'))
    cls = community.rsplit('::', 1)[0] if community and '::' in community else None
    hits = sorted(d for d in defined if d not in taken and destructor_fits(d, spec, fn))
    thunks = sorted(d for d in defined if d not in taken and cls and dtor_thunk_decoration(d)
                    and dtor_thunk_decoration(d)[0] in spec['symbols']
                    and member(dtor_thunk_decoration(d)[1]) == member(cls))
    out = {'symbol': None, 'how': None, 'candidates': [], 'warnings': [], 'choice': None}
    if len(hits) == 1 and not thunks:
        out.update(symbol=hits[0], how='destructor kind')
        return out
    pool = hits + thunks
    if thunks:
        cands, steps = narrow(pool, fn, None, lambda d: {}, size_of, matcher)
        if len(cands) == 1 and (len(pool) == 1 or steps):
            out.update(symbol=cands[0], how='destructor kind' + (', narrowed by ' + ', '.join(steps) if steps else ''))
            return out
    if hits:
        size = parse_rva(fn['size'])
        ranked = sorted(hits, key=lambda d: (abs(size_of(d) - size), d))
        exact = size_of(ranked[0]) == size
        out.update(symbol=ranked[0], how='destructor kind, ' + ('size match' if exact else 'closest size'),
                   choice={'rva': hex(parse_rva(fn['rva'])), 'bound': ranked[0], 'size': size,
                           'candidates': [{'symbol': d, 'size': size_of(d)} for d in ranked]})
    return out


def bind(task_dir, obj_path, image_path=None, objdump=None, repo=REPO):
    """Update task.json and symbols.json in place; returns a report dict (see `describe`)."""
    task_dir = Path(task_dir)
    task = json.loads((task_dir / 'task.json').read_text())
    map_name = task.get('symbols', 'symbols.json')
    public = map_name.startswith('reports/')
    smap_path = (Path(repo) / map_name) if public else task_dir / map_name
    smap = json.loads(smap_path.read_text())
    before = json.loads(json.dumps(smap.get('symbols', {})))
    symbols = smap.setdefault('symbols', {})
    found = {}  # name -> (how, community name) for provenance of public additions
    obj_bytes = Path(obj_path).read_bytes()
    obj = CoffObject(obj_bytes)
    image = PeImage(Path(image_path).read_bytes()) if image_path and Path(image_path).is_file() else None
    # Defaults only for names this object references, so a unit without a static local lists no ignored hint.
    referenced = {s.name for s in obj.symbols.values()}
    default_rvas, default_tls = split_hints({n: v for n, v in crt_defaults(repo, task.get('build_id')).items()
                                             if n in referenced})
    hints = {**default_rvas, **unit_hints(repo, task), **load_hints(task_dir)}
    tls_hints = {**default_tls, **load_tls_hints(task_dir)}
    tls_used = set()
    names = Names(find_undname(objdump))
    defined = defined_functions(obj)
    names.load(list(defined) + [s.name for s in obj.symbols.values()] + list(hints) + list(tls_hints))
    report = {'functions': [], 'references': [], 'unbound_functions': [], 'unbound_references': [],
              'unbound_thread_locals': [], 'unused_hints': [],
              'renamed': [], 'ignored_hints': [], 'destructor_choices': [], 'warnings': [], 'changed': False}
    if image is not None and any(s.name == '__std_terminate' and s.section == SYM_UNDEFINED
                                 for s in obj.symbols.values()):
        from compare_runtime import termination_thunk
        try:
            entry = termination_thunk(image)
        except Reject:
            pass  # An unsupported or ambiguous import remains unbound and cannot pass.
        else:
            previous = symbols.get('__std_terminate')
            if previous is None or previous == dict(entry, size=None):
                symbols['__std_terminate'] = entry
                found['__std_terminate'] = ('verified runtime import', None)
                report['changed'] |= previous != entry
    if annotate_destructors(task, repo):
        report['changed'] = True

    def size_of(d):
        return obj.section(defined[d]).raw_size

    # How many referenced symbols share each member name: a hint written as the bare member name
    # (`g_tlsErrorContext`) binds only when exactly one referenced symbol has that member name.
    member_count = {}
    for s in obj.symbols.values():
        if s.section == SYM_UNDEFINED and names(s.name):
            member_count[member(names(s.name))] = member_count.get(member(names(s.name)), 0) + 1

    def hint_key(name, table):
        """The key of `table` (hints or tls_hints) that names the symbol `name`, or None.

        In order: the decorated name, the qualified name, then the bare member name when no other
        referenced symbol shares it.
        """
        if name in table:
            return name
        q = names(name)
        if q and q in table:
            return q
        m = member(q) if q else None
        if m and m != q and m in table and member_count.get(m) == 1:
            return m
        return None

    def hint_for(name):
        key = hint_key(name, hints)
        return hints[key] if key is not None else None

    header = header_declarations(repo, task.get('compiled'))
    matcher = target_matcher(repo, obj_bytes)
    resolved = resolve_functions(task, defined, names, hints, size_of, matcher, header)
    for fn in task['functions']:
        rva = parse_rva(fn['rva'])
        old = fn.get('symbol') or ''
        res = resolved[fn['rva']]
        how, new = res['how'], res['symbol']
        report['warnings'] += res['warnings']
        if res['choice']:
            report['destructor_choices'].append(res['choice'])
        if new is None:
            candidates = sorted(d for d in defined if d not in {r['symbol'] for r in resolved.values()})
            report['unbound_functions'].append({'rva': hex(rva), 'community_name': fn.get('community_name'),
                                                'symbol': old, 'defined_in_object': candidates[:12],
                                                'expected': fn.get('destructor'), 'overloads': res['candidates']})
            continue
        if new != old:
            if old and not old.startswith(UNBOUND):
                report['renamed'].append({'rva': hex(rva), 'old': old, 'new': new})
                if symbols.get(old, {}).get('rva') == rva:
                    del symbols[old]
            fn['symbol'] = new
            report['changed'] = True
        entry = {'rva': rva, 'size': parse_rva(fn['size'])}
        if symbols.get(new) != entry:
            symbols[new] = entry
            found[new] = (how, fn.get('community_name'))
            report['changed'] = True
        # A unit edit can re-decorate an accepted function (a method turned virtual, say). The record's
        # frozen map still carries the old decoration at this RVA, and the comparator rejects a second
        # name there unless a fold declares it.
        folded = set().union(*(set(g) for g in smap.get('folds', []) if new in g))
        for rec in task.get('export', {}).get('unit_already_records', []):
            gone = rec.get('symbol')
            if (gone and gone != new and parse_rva(rec['rva']) == rva and gone not in defined
                    and gone not in folded and symbols.get(gone, {}).get('rva') == rva):
                del symbols[gone]
                report['renamed'].append({'rva': hex(rva), 'old': gone, 'new': new})
                report['changed'] = True
        report['functions'].append({'rva': hex(rva), 'symbol': new, 'how': how})

    bound_at = {parse_rva(f['rva']): f['symbol'] for f in report['functions']}
    for h, r in hints.items():
        # A hint at a compared function's RVA is meant to name it; one that does not must be seen.
        if r not in {parse_rva(f['rva']) for f in task['functions']}:
            continue
        got = bound_at.get(r)
        if got is not None and (got == h or names(got) == h):
            continue
        hits = [d for d in defined if d == h or names(d) == h]
        reason = ('not defined in the compiled object' if not hits else
                  f'matches {len(hits)} definitions' if len(hits) > 1 else f'{hex(r)} was bound to {got} instead')
        if not hits and dtor_decoration(h) and dtor_decoration(h)[0] != '??1':
            reason += ('; the compiler emits a deleting destructor only beside the vftable, i.e. in a unit '
                       'that defines a constructor or otherwise references the vftable')
        report['ignored_hints'].append({'hint': h, 'rva': hex(r), 'reason': reason})
    compared = {fn['symbol']: fn for fn in task['functions'] if fn['symbol'] in defined}
    starts = function_starts(repo)
    own = set(compared)
    defined_sections = set(defined.values())
    for name, fn in compared.items():
        fn_rva = parse_rva(fn['rva'])
        refs = pack_references(repo, fn)
        known = {r for r, _ in refs}
        calls, places = lifetime_calls(repo, fn)
        life_known = {r for entries in calls.values() for r, _ in entries}
        life_refs = [(r, [n]) for entries in calls.values() for r, n in entries if n]
        extra = funclets(obj, defined[name], defined_sections)
        # (section, target RVA of its start or None, lifetime state or None, is a funclet)
        parts = [(defined[name], fn_rva, None, False)]
        for index, where in sorted(extra.items()):
            state = where[0] if where else None
            base = places[state] - where[1] if where and state in places else None
            parts.append((index, base, state, True))
        group = {p[0] for p in parts}
        for index, base, state, is_funclet in parts:
            pending = []
            for rel, target in outgoing(obj, index):
                ref = target.name
                if target.section in group or ref in own or ref in DIRECTORY_SYMBOLS:
                    continue
                if rel.kind == SECREL:
                    # A TLS offset is not an RVA: neither the pack's references nor the target's field
                    # name it, so only an explicit hint binds it.
                    q = names(ref)
                    key = hint_key(ref, tls_hints)
                    if key is not None:
                        tls_used.add(key)
                    if ref in symbols:
                        continue
                    if key is None:
                        offset = declared_tls_offset(member(q) if q else ref)
                        if offset is not None and base is not None and image is not None:
                            sec = obj.section(index)
                            try:
                                addend = struct.unpack_from('<I', sec.data, rel.offset)[0]
                                (field,) = struct.unpack('<I', image.read(base + rel.offset, 4, 'bind')[1])
                                start, end, _ = image.tls_template()
                            except (Reject, struct.error, TypeError):
                                field = None
                            if field is not None and field - addend == offset and offset < end - start:
                                symbols[ref] = {'kind': 'thread-local', 'tls_offset': offset, 'size': None}
                                found[ref] = ('thread-local name', None)
                                report['references'].append({'symbol': ref, 'tls_offset': hex(offset),
                                                             'how': 'thread-local name',
                                                             **({'from': 'funclet'} if is_funclet else {})})
                                report['changed'] = True
                                continue
                        if ref not in report['unbound_thread_locals']:
                            report['unbound_thread_locals'].append(ref)
                        continue
                    symbols[ref] = {'kind': 'thread-local', 'tls_offset': tls_hints[key], 'size': None}
                    found[ref] = ('thread-local hint', None)
                    report['references'].append({'symbol': ref, 'tls_offset': hex(tls_hints[key]),
                                                 'how': 'thread-local hint',
                                                 **({'from': 'funclet'} if is_funclet else {})})
                    report['changed'] = True
                    continue
                hinted = hint_for(ref)
                if ref in symbols and hinted is not None and symbols[ref].get('rva') != hinted:
                    # An entry bound earlier by position from a misaligned candidate can name another
                    # listed target; the Drafter's hint is the later, explicit statement.
                    report['references'].append({'symbol': ref, 'rva': hex(hinted), 'how': 'hint, replaced '
                                                 + hex(symbols[ref]['rva'])})
                    symbols[ref] = {'rva': hinted, 'size': None}
                    found[ref] = ('hint, replaced', None)
                    report['changed'] = True
                if ref not in symbols:
                    pending.append((rel, target))
            for rel, target in pending:
                ref = target.name
                if ref in symbols:  # bound earlier in this loop
                    continue
                how, value = None, hint_for(ref)
                if value is not None:
                    how = 'hint'
                accept = known | life_known if is_funclet else known
                contradicted = False
                pos, addend = None, 0
                if value is None and base is not None:
                    pos = by_position(image, base, rel)
                    # The field encodes the symbol plus the member offset the candidate stores in it, and
                    # the comparator adds that offset back, so the symbol's own RVA is what is bound. The
                    # pack lists the address actually used, so either form is evidence.
                    addend = field_addend(obj, index, rel) if pos is not None else 0
                    if pos is not None and (pos in accept or pos - addend in accept):
                        shown = pos if pos in accept else pos - addend
                        how, value = ('object lifetime position' if shown in life_known and shown not in known
                                      else 'position'), pos - addend
                    elif (pos is not None and is_funclet and state is not None and rel.kind in REL32_TAIL
                          and starts is not None and pos in starts):
                        # The compiler's own destructor of a local is a function of the image the pack
                        # need not list; the relocated target being a known function start is the evidence.
                        how, value = 'unwind funclet position', pos
                    contradicted = value is None and pos is not None and pos not in accept and pos - addend not in accept
                want = pool_constant_bytes(ref) or (string_literal_bytes(ref) or (None,))[0]
                if value is None and want is not None and image is not None:
                    # A float, vector or string literal: its name spells the value, so the bytes at the
                    # target's own field (when the candidate's code lines up) or at the one address the
                    # pack lists for the function that holds exactly that value is the evidence.
                    if pos is not None and constant_at(image, pos - addend, want):
                        how, value, contradicted = 'literal value at position', pos - addend, False
                    else:
                        hits = sorted(r for r in accept if constant_at(image, r, want))
                        if len(hits) == 1:
                            how, value, contradicted = 'literal value among the pack references', hits[0], False
                        elif not hits and (string_literal_bytes(ref) or (None, False))[1]:
                            # Last resort, for a string the pack does not list: the one place in the image's
                            # data that holds exactly that text. The comparator still checks the binding.
                            found_at = find_literal(image, want)
                            if len(found_at) == 1:
                                how, value = 'literal value, the only such string in the image', found_at[0]
                if value is None:
                    q = names(ref)
                    pool = refs + life_refs if is_funclet else refs
                    for key in (q, member(q)):
                        if not key:
                            continue
                        hits = {r for r, cns in pool for c in cns if (c == key if key == q else member(c) == key)}
                        if len(hits) == 1:
                            how, value = ('community name' if key == q else 'member name'), hits.pop()
                            break
                if value is None and is_funclet and state is not None and not contradicted:
                    # An unwind funclet destroys what its state owns: when the pack lists exactly one
                    # destructor call for that state and the funclet leaves exactly one name unbound,
                    # that is the call. The comparator still checks the encoded address.
                    targets = {r for r, _ in calls.get(state, [])}
                    names_left = {t.name for _, t in pending if t.name not in symbols and hint_for(t.name) is None}
                    if len(targets) == 1 and names_left == {ref}:
                        how, value = 'object lifetime', targets.pop()
                if value is None:
                    if ref not in report['unbound_references']:
                        report['unbound_references'].append(ref)
                    continue
                symbols[ref] = {'rva': value, 'size': None}
                found[ref] = (how, None)
                report['references'].append({'symbol': ref, 'rva': hex(value), 'how': how,
                                             **({'from': 'funclet'} if is_funclet else {})})
                report['changed'] = True
    for key, offset in tls_hints.items():
        if key not in tls_used:
            report['ignored_hints'].append({'hint': key, 'rva': f'tls:{hex(offset)}',
                                            'reason': 'no SECREL reference of a compared function or funclet has that name'})
    # A hint that names no symbol of the object at all is usually misspelt or left over from an
    # earlier draft; listing it by name is cheaper than finding out why a reference stayed unbound.
    compared_rvas = {parse_rva(f['rva']) for f in task['functions']}
    in_object = {hint_key(s.name, hints) for s in obj.symbols.values()}
    report['unused_hints'] = sorted(h for h, r in hints.items() if h not in in_object and r not in compared_rvas)
    if report['changed']:
        if public:
            publish(Path(repo), map_name, smap, before, found)
        else:
            smap_path.write_text(json.dumps(smap, indent=2) + '\n')
        (task_dir / 'task.json').write_text(json.dumps(task, indent=2) + '\n')
    return report


def provenance_entry(name, entry, found):
    """Provenance of one entry bind publishes; a thread-local entry names its offset, never an RVA."""
    how = found.get(name, ('unknown', None))[0]
    if entry.get('kind') == 'thread-local':
        return {'name': name, 'tls_offset': hex(entry['tls_offset']), 'size_from': None, 'community_name': None,
                'note': f'bound by tools/verifier/bind.py ({how}) from a tls: bind hint or the tls_0x<offset> name; the offset is the one the '
                        'target code adds to the TLS block, the decorated name is the reconstruction\'s'}
    return {'name': name, 'rva': hex(entry['rva']), 'size_from': 'task' if entry.get('size') else None,
            'community_name': found.get(name, (None, None))[1],
            'note': f'bound by tools/verifier/bind.py ({how}) from the task pack; the decorated name is the '
                    'reconstruction\'s'}


def publish(repo, map_name, smap, before, found):
    """Apply bind's edits to the repository map through tools/symbol_map.py (see the module doc)."""
    after = smap['symbols']
    touched = {n: e for n, e in after.items() if before.get(n) != e}
    incoming = {'schema': 1, 'build_id': smap.get('build_id'), 'symbols': touched,
                '_provenance': {'entries': [provenance_entry(n, e, found) for n, e in touched.items()]}}
    removed = [n for n in before if n not in after]
    symbol_maps.apply_change(repo, map_name, incoming, remove=removed, allow_unpinned_change=True)


def describe(report, task_dir):
    """Short lines for the attempt output: what was bound, renamed or is still missing, and where to fix it."""
    lines = []
    bound = [f for f in report['functions'] if f['how'] != 'kept'] + report['references']
    if bound:
        lines.append('  bound: ' + '; '.join(
            f'{b.get("rva") or "tls+" + b.get("tls_offset", "?")} {"<-" if "symbol" in b else ""} {b["symbol"][:60]} ({b["how"]})' for b in bound[:6])
            + (f' ... {len(bound) - 6} more' if len(bound) > 6 else ''))
    for r in report['renamed']:
        lines.append(f'  decorated name changed for {r["rva"]}: {r["old"]} -> {r["new"]}')
    hints = Path(task_dir) / HINTS
    for c in report.get('destructor_choices', []):
        lines.append(f'  destructor {c["rva"]} ({c["size"]} B) bound to {c["bound"]} of '
                     + ', '.join(f'{x["symbol"]} {x["size"]} B' for x in c['candidates']))
    for w in report.get('warnings', []):
        lines.append(f'  WARNING {w}')
    for h in report.get('ignored_hints', []):
        lines.append(f'  WARNING bind hint {h["hint"]} -> {h["rva"]} ignored: {h["reason"]}')
    for f in report['unbound_functions']:
        spec = f.get('expected')
        if spec:
            lines.append(f'  UNBOUND function {f["rva"]} ({f["community_name"]}): the target is a {spec["kind"]} '
                         f'({spec["evidence"]}); the object defines no {"/".join(spec["symbols"])} of the class. '
                         'A deleting destructor is emitted beside the vftable, so the unit must define a '
                         f'constructor (or otherwise reference the vftable); or add a hint to {hints}')
        elif f.get('overloads'):
            lines.append(f'  UNBOUND function {f["rva"]} ({f["community_name"]}): {len(f["overloads"])} definitions '
                         'carry that name and neither the declared signature, the size nor the published target '
                         'hash tells them apart. Put the signature on the header line '
                         f'(`// {f["rva"]} Class::Method(int) const`), or add the one `CI hash:` line that names it:')
            lines += ['    ' + line for line in hint_lines(f['rva'], f['overloads'][:6])]
        else:
            lines.append(f'  UNBOUND function {f["rva"]} ({f["community_name"]}): the object defines nothing under '
                         'that name. If the unit defines it under another name, write that name on its header line '
                         f'(`// {f["rva"]} Class::Method`) or add `// CI hash: {f["rva"]} <decorated name>`; '
                         f'locally {{"<decorated or Class::Method name>": "{f["rva"]}"}} in {hints} also works')
        if f['defined_in_object']:
            lines.append('    defined in object: ' + ', '.join(f['defined_in_object'][:6]))
    for name in report['unbound_references']:
        lines.append(f'  UNBOUND reference {name}: add {{"{name}": "0x<rva from the pack table>"}} to {hints}')
    for name in report.get('unbound_thread_locals', []):
        lines.append(f'  UNBOUND thread-local {name}: add {{"{name}": "tls:0x<offset>"}} to {hints}; the offset is '
                     'the displacement the target adds to the TLS block, the same for every function using it')
    if report.get('unused_hints'):
        shown = report['unused_hints']
        lines.append(f'  unused bind hints ({len(shown)}): no symbol of the object has these names '
                     '(misspelt, or the unit no longer references them): ' + ', '.join(shown[:12])
                     + (f' ... {len(shown) - 12} more' if len(shown) > 12 else ''))
    open_names = ([(n, '0x<rva>') for n in report['unbound_references']]
                  + [(n, 'tls:0x<offset>') for n in report.get('unbound_thread_locals', [])])
    if len(open_names) > 3:
        lines.append(f'  paste into {hints.name}: ' + json.dumps({n: v for n, v in open_names}))
    return lines


def preflight(task_dirs, repo=REPO):
    """Check selected functions and private reference maps before publishing any unit."""
    declarations = {}
    for directory in task_dirs:
        directory = Path(repo) / directory
        task = json.loads((directory / 'task.json').read_text())
        targets = {}
        definitions = {f['symbol'] for f in task['functions']}
        entries = [(f['symbol'], {'rva': f['rva']}) for f in task['functions']]
        private_map = directory / 'symbols.json'
        if private_map.is_file():
            objects = sorted(directory.glob('attempts/[0-9][0-9][0-9]/candidate.obj'))
            active = ({s.name for s in CoffObject(objects[-1].read_bytes()).symbols.values()}
                      if objects else None)
            entries += [(name, entry) for name, entry in
                        json.loads(private_map.read_text())['symbols'].items()
                        if active is None or name in active]
        for name, entry in entries:
            if 'rva' not in entry or name.startswith(UNBOUND) or name.startswith('??_7'):
                continue
            key = (task.get('build_id'), parse_rva(entry['rva']))
            name_key = (task.get('build_id'), name)
            target = targets.setdefault(name_key, key[1])
            if target != key[1]:
                raise ValueError(f'symbol {name} is bound to two RVAs')
            if name not in definitions:
                continue
            previous = declarations.setdefault(key, name)
            if previous != name:
                raise ValueError(f'conflicting symbol declarations at {key[0]} {hex(key[1])}: '
                                 f'{previous} versus {name}')


def unit_map(task_dir, repo=REPO):
    """Freeze this unit's reference namespace without changing any existing public map."""
    task_dir = Path(repo) / task_dir
    path = task_dir / 'task.json'
    task = json.loads(path.read_text())
    private = json.loads((task_dir / 'symbols.json').read_text())
    objects = sorted(task_dir.glob('attempts/[0-9][0-9][0-9]/candidate.obj'))
    if not objects:
        raise ValueError('unit reference map needs a compiled candidate object')
    active = {s.name for s in CoffObject(objects[-1].read_bytes()).symbols.values()}
    symbols = {n: e for n, e in private['symbols'].items() if n in active}
    for fn in task['functions']:
        entry = {'rva': parse_rva(fn['rva']), 'size': fn['size']}
        if fn['symbol'] in symbols and symbols[fn['symbol']]['rva'] != entry['rva']:
            raise ValueError(f"symbol {fn['symbol']} is bound to two RVAs")
        symbols[fn['symbol']] = entry
    groups = {}
    for name, entry in symbols.items():
        if 'rva' in entry:
            groups.setdefault(parse_rva(entry['rva']), []).append(name)
    folds = [names for names in groups.values() if len(names) > 1]
    # A content-addressed map is immutable. New bindings get a new map; old records keep theirs.
    import hashlib
    payload = {'schema': 1, 'build_id': task['build_id'], 'symbols': symbols, 'folds': folds,
               '_provenance': {'entries': [provenance_entry(n, e, {}) for n, e in symbols.items()],
                               'note': 'Unit reference namespace from the task and candidate object'}}
    digest = hashlib.sha256(symbol_maps.serialize(payload)).hexdigest()
    map_name = f"reports/{task['build_id']}/unit-symbols/{digest}.json"
    from sparse_checkouts import ensure
    ensure(repo, [map_name])
    symbol_maps.create(repo, map_name, payload)
    task['symbols'] = map_name
    path.write_text(json.dumps(task, indent=2) + '\n')


def main(argv=None):
    import argparse
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--task')
    p.add_argument('--list', type=Path, help='preflight every task before binding any task')
    p.add_argument('--unit-maps', action='store_true', help='keep reference names in immutable unit maps')
    p.add_argument('--object', default=None, help='Default: the newest attempts/<NNN>/candidate.obj')
    p.add_argument('--image', default=None, help='Default: .local/verifier/config.json "image"')
    a = p.parse_args(argv)
    if a.list:
        directories = [line.strip() for line in a.list.read_text().splitlines()
                       if line.strip() and not line.lstrip().startswith('#')]
        preflight(directories)
        for directory in directories:
            if a.unit_maps:
                task_path = Path(directory) / 'task.json'
                task = json.loads(task_path.read_text())
                task['symbols'] = 'symbols.json'
                task_path.write_text(json.dumps(task, indent=2) + '\n')
            result = main(['--task', directory])
            if result:
                return result
            if a.unit_maps:
                unit_map(directory)
        return 0
    if not a.task:
        p.error('--task or --list is required')
    task_dir = Path(a.task)
    obj = a.object
    if obj is None:
        objs = sorted(task_dir.glob('attempts/[0-9][0-9][0-9]/candidate.obj'))
        if not objs:
            raise SystemExit(f'no attempts/*/candidate.obj under {task_dir}; pass --object')
        obj = objs[-1]
    config = {}
    cfg = REPO / '.local/verifier/config.json'
    if cfg.is_file():
        config = json.loads(cfg.read_text())
    report = bind(task_dir, obj, a.image or config.get('image'), config.get('objdump'))
    print('\n'.join(describe(report, task_dir)) or '  nothing to bind')
    return 1 if (report['unbound_functions'] or report['unbound_references'] or report['unbound_thread_locals']
                 or report['ignored_hints']) else 0


if __name__ == '__main__':
    raise SystemExit(main())
