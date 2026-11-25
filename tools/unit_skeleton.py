"""Starting files for a reconstruction unit and a compact per-function sheet, from a task directory.

A Drafter with a small context (or a short tool-output limit) fails on paperwork and long files
more often than on code: a unit has to start with the right header lines and labels before the
lint accepts it, and the pack facts for one function are spread over several files. This module
renders both from what the pack export already wrote under `.local/`:

- `skeleton_files(task_dir)` -> (header path, header text, source path, source text): a header
  comment with every line the lint asks for, `Labels: v2` label lines for the names it declares,
  the class shell (base include or stand-ins sized from the image, community declarations of the
  compared functions) and one stub per compared function. Each stub body is the statement
  `SKELETON_TODO_BODY;`, an undeclared name, so an unfilled stub never compiles and so can never
  pass the comparator; the paperwork placeholders `SKELETON_TODO_MODEL` and `SKELETON_TODO_ORIGIN`
  are words the lint refuses in any tracked, staged or accepted file (lint_reconstruction.py,
  "skeleton not filled").
- `sheet_pages(task_dir, rva)`: one function's facts (signature, convention, references, memory
  operands, sibling pointers, listing, decompiler output) cut into pages of at most SHEET_CAP
  characters, so one page always fits one tool output.

`community_label` and `skeleton` are the contributor-flow skeleton writer's (`tools/contrib.py`
`start`) functions, kept call-compatible so that tool can import them from here instead of
carrying its own copy.
"""
import json
from pathlib import Path, PurePosixPath
import re
import sys
import textwrap

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from lint_reconstruction import DEFAULT_RECIPE, SKELETON_MARKER  # noqa: E402,F401 (re-exported for the CLIs and tests)

BODY_MARKER = 'SKELETON_TODO_BODY'
MODEL_MARKER = 'SKELETON_TODO_MODEL'
ORIGIN_MARKER = 'SKELETON_TODO_ORIGIN'
# One page of a sheet. Small enough for the shortest tool-output limit seen in Drafter runs
# (long instruction files came back cut off), large enough for a whole small function's listing.
SHEET_CAP = 4000

# Pinned community naming sources (SOURCES.md) that tools/check_labels.py and check_origin.py read
# from .local/sources/: repository -> (clone path, revision, licence word of its labels).
COMMUNITY_SOURCES = {
    'CharmedBaryon/CommonLibSSE-NG': ('.local/sources/CommonLibSSE-NG', 'b93280e832f263dbef44e44cbe2936622a02f91a', 'MIT'),
    'powerof3/CommonLibSSE': ('.local/sources/CommonLibSSE-po3', '654e55f7979c1733033d5dbef176e43827bac944', 'GPL-3.0'),
    'meh321/AddressLibraryDatabase': ('.local/sources/AddressLibraryDatabase', '0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91',
                                      'permission'),
}
# Shorter spellings of the same sources in pack and inventory name-source text, checked in this
# order after the full repository names (NG before po3: "CommonLibSSE" is a prefix of both).
SOURCE_ALIASES = (
    ('CommonLibSSE-NG', 'CharmedBaryon/CommonLibSSE-NG'),
    ('CommonLibSSE-po3', 'powerof3/CommonLibSSE'),
    ('powerof3', 'powerof3/CommonLibSSE'),
    ('meh321', 'meh321/AddressLibraryDatabase'),
    ('Address Library name', 'meh321/AddressLibraryDatabase'),
)
GPL_NOTE = '// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).'
BUILTIN = {'void', 'bool', 'char', 'short', 'int', 'long', 'float', 'double', 'unsigned', 'signed', 'const',
           'volatile', 'auto', 'std', 'virtual', 'static', 'inline', 'override', 'final', 'struct', 'class',
           'enum', 'typename', 'nullptr', 'true', 'false', 'wchar_t', 'char16_t', 'char32_t', 'size_t', 'RE'}


class SkeletonError(Exception):
    pass


# ------------------------------------------------------------------ inline Ni bases
#
# A deleting destructor that stores the NiRefObject vftable and decrements the object counter
# itself has the whole base chain inlined. The shared NiObject.h declares ~NiRefObject and
# ~NiObject out of line, so a unit that includes it gets a call to a separate base destructor
# instead and misses by a few bytes. Such units get local stand-ins with inline destructors, the
# form of the accepted reconstruction/netimmerse/NiExtraData.h and NiInterpolator.h.
INLINE_BASE_REFS = ('VTABLE_NiRefObject', 'NiRefObject::TotalObjectCount')
INLINE_BASE_ROOTS = ('NiRefObject', 'NiObject')
_NG = 'COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)'
# Opaque declarations from the pinned NG headers: no object layout or enum values inferred.
# BSTEvent.h, NiPointer.h, NiAllocator.h, BSStorage.h, BSIMusicTrack.h,
# BSContainer.h, MagicSystem.h and EffectArchetypes.h.
SUPPORT_DECLARATIONS = {
    'BSTEventSource': 'template <class Event> class BSTEventSource;',
    'NiPointer': 'template <class T> class NiPointer;',
    'BSEventNotifyControl': 'enum class BSEventNotifyControl : int;',
    'NiMemEventType': 'enum class NiMemEventType : int;',
    'BSStorageDefs::ErrorCode': 'namespace BSStorageDefs { enum class ErrorCode : int; }',
    'BSStorageDefs::SeekMode': 'namespace BSStorageDefs { enum class SeekMode : int; }',
    'TrackType': 'enum class TrackType : std::uint32_t;',
    'BSContainer::ForEachResult': 'namespace BSContainer { enum class ForEachResult : int; }',
    'MagicSystem::CastingSource': 'namespace MagicSystem { enum class CastingSource : int; }',
    'MagicSystem::CastingType': 'namespace MagicSystem { enum class CastingType : int; }',
    'MagicSystem::Delivery': 'namespace MagicSystem { enum class Delivery : int; }',
    'MagicSystem::SoundID': 'namespace MagicSystem { enum class SoundID : int; }',
    'MagicSystem::SpellType': 'namespace MagicSystem { enum class SpellType : int; }',
    'EffectArchetype': ('struct EffectArchetypes { enum class ArchetypeID : int; };\n'
                       'using EffectArchetype = EffectArchetypes::ArchetypeID;'),
}
_NI_SLOTS = [
    ('const NiRTTI*', 'GetRTTI() const'), ('NiNode*', 'AsNode()'), ('NiSwitchNode*', 'AsSwitchNode()'),
    ('BSFadeNode*', 'AsFadeNode()'), ('BSMultiBoundNode*', 'AsMultiBoundNode()'), ('BSGeometry*', 'AsGeometry()'),
    ('NiTriStrips*', 'AsTriStrips()'), ('BSTriShape*', 'AsTriShape()'),
    ('BSSegmentedTriShape*', 'AsSegmentedTriShape()'), ('BSSubIndexTriShape*', 'AsSubIndexTriShape()'),
    ('BSDynamicTriShape*', 'AsDynamicTriShape()'), ('NiGeometry*', 'AsNiGeometry()'),
    ('NiTriBasedGeom*', 'AsNiTriBasedGeom()'), ('NiTriShape*', 'AsNiTriShape()'), ('NiParticles*', 'AsParticlesGeom()'),
    ('BSLines*', 'AsLinesGeom()'), ('bhkNiCollisionObject*', 'AsBhkNiCollisionObject()'),
    ('bhkBlendCollisionObject*', 'AsBhkBlendCollisionObject()'),
    ('bhkAttachmentCollisionObject*', 'AsBhkAttachmentCollisionObject()'), ('bhkRigidBody*', 'AsBhkRigidBody()'),
    ('bhkLimitedHingeConstraint*', 'AsBhkLimitedHingeConstraint()'),
    ('NiObject*', 'CreateClone(NiCloningProcess& a_cloning)'), ('void', 'LoadBinary(NiStream& a_stream)'),
    ('void', 'LinkObject(NiStream& a_stream)'), ('bool', 'RegisterStreamables(NiStream& a_stream)'),
    ('void', 'SaveBinary(NiStream& a_stream)'), ('bool', 'IsEqual(NiObject* a_object)'),
    ('void', 'ProcessClone(NiCloningProcess& a_cloning)'), ('void', 'PostLinkObject(NiStream& a_stream)'),
    ('bool', 'StreamCanSkip()'), ('const NiRTTI*', 'GetStreamableRTTI() const'),
    ('std::uint32_t', 'GetBlockAllocationSize() const'), ('NiObjectGroup*', 'GetGroup() const'),
    ('void', 'SetGroup(NiObjectGroup* a_group)'), ('NiControllerManager*', 'AsNiControllerManager()'),
]
INLINE_BASE_FORWARD = sorted({ret.rstrip('*').split()[-1] for ret, _ in _NI_SLOTS if ret.endswith('*')}
                             | {'NiStream', 'NiCloningProcess', 'NiObjectGroup'})


def inline_base_blocks():
    """The NiRefObject and NiObject stand-ins with inline destructors, as header text."""
    names = [sig.split('(')[0] for _, sig in _NI_SLOTS]
    slots = [f'    virtual {ret} {sig};  // {i:02X}' for i, (ret, sig) in enumerate(_NI_SLOTS, 2)]
    return '\n'.join([
        f'// NiRefObject: STANDIN {_NG}',
        f'// ~NiRefObject, DeleteThis, _refCount, _pad0C: {_NG}',
        '// ms_totalObjects: GUESS(low); NG reaches the counter through GetTotalObjectCount()',
        'class NiRefObject',
        '{',
        'public:',
        '    // Inline because the target inlines it into the compared deleting destructor.',
        '    virtual ~NiRefObject()',
        '    {',
        '        // hot path: the engine drops the shared object counter atomically on every destruction',
        '        _InterlockedDecrement(&ms_totalObjects);',
        '    }',
        '    virtual void DeleteThis();  // 01',
        '',
        '    static volatile long ms_totalObjects;',
        '',
        '    std::uint32_t _refCount{ 0 };  // 08',
        '    std::uint32_t _pad0C;          // 0C',
        '};',
        'static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");',
        '',
        f'// NiObject: STANDIN {_NG} EXE_RTTI',
        '// Slots in NG\'s order, declared without bodies (only the order matters here).',
        f'// ~NiObject, {", ".join(names)}: {_NG}',
        'class NiObject : public NiRefObject',
        '{',
        'public:',
        '    // Inline (empty) for the same reason as ~NiRefObject.',
        '    ~NiObject() override {}  // 00',
        *slots,
        '};',
        'static_assert(sizeof(NiObject) == 0x10, "NiObject size");',
        ''])


def inlines_ni_base(fn):
    """True when a compared deleting destructor does the NiRefObject cleanup itself (its references
    include the NiRefObject vftable or the object counter), so no base destructor is called."""
    kind = (fn.get('destructor') or {}).get('kind') or ''
    if 'deleting' not in kind:
        return False
    refs = readme_section(fn.get('readme') or '', 'References leaving the function')
    return any(marker in refs for marker in INLINE_BASE_REFS)


# ------------------------------------------------------------------ labels

def community_label(name_source):
    """The COMMUNITY(...) label an inventory or pack name source supports, and its licence word."""
    text = name_source or ''
    repo = next((r for r in COMMUNITY_SOURCES if r in text), None)
    if repo is None:
        repo = next((full for alias, full in SOURCE_ALIASES if alias in text), None)
    if repo is None:
        return None, None
    _path, rev, licence = COMMUNITY_SOURCES[repo]
    return f'COMMUNITY({repo}@{rev[:7]}, {licence})', licence


def is_gpl(label):
    return bool(label) and 'GPL' in label


# ------------------------------------------------------------------ the contributor-flow writer

def skeleton(fn, cls, method, area, drafted_by, recipe, code_origin=None):
    """Compatibility entry point; render through the same engine as task skeletons."""
    unit = {'cls': cls, 'area': area, 'header': f'reconstruction/{area}/{cls}.h',
            'compiled': f'reconstruction/{area}/{cls}.cpp', 'brief': '', 'material': [],
            'task': {'task_id': f'contrib-{cls.lower()}', 'build_id': fn['build_id'], 'recipe': recipe},
            'functions': [dict(fn, community_name=f'{cls}::{method}',
                               pack_json={'identity': {'name_source': fn.get('name_source')}})],
            'evidence': fn.get('evidence'), 'contributor_origin': True, 'code_origin': code_origin}
    _hp, header, _cp, source = render_unit(unit, drafted_by)
    return header, source


def root_include_recipe(repo, recipe):
    """Use an additive recipe carrying the already-admitted reconstruction include root."""
    path = Path(repo) / recipe
    doc = _json(path)
    flags = doc.get('flags', [])
    if (any(flag in ('/Ireconstruction', '-Ireconstruction') for flag in flags)
            or any(flags[i:i + 2] in (['/I', 'reconstruction'], ['-I', 'reconstruction'])
                   for i in range(len(flags)))):
        return recipe
    variant = path.with_stem(path.stem + '-root-includes')
    added = _json(variant)
    if added and added == dict(doc, flags=flags + ['/Ireconstruction']):
        return variant.relative_to(Path(repo)).as_posix()
    from reconstruction_includes import root_recipe
    try:
        return root_recipe(repo, recipe)
    except (ValueError, OSError) as exc:
        raise SkeletonError(str(exc)) from None


def contributor_files(repo, functions, cls, area, drafted_by, recipe, sources=None, code_origin=None):
    """Adapt public declarations and contributor-owned packs to the ordinary unit renderer.

    Never consult internal queues, class exports or sibling indexes. Read community sources
    only at the approved immutable Git revisions. Existing reviewed headers remain untouched.
    """
    from declaration_kit import pinned_class, notice
    from header_index import advice
    repo = Path(repo)
    facts, notices, seen, current = {}, [], set(), cls
    while current and current not in seen:
        seen.add(current)
        info = pinned_class(repo, current, sources=sources) if sources is not None else pinned_class(repo, current)
        if not info:
            break
        facts[current] = info
        text = notice(repo, info, sources=sources) if sources is not None else notice(repo, info)
        if text not in notices:
            notices.append(text)
        current = info['bases'][0] if info['bases'] else None
    members, hints = [], []
    conflicts = []
    for name, info in facts.items():
        conflicts += [f'{name}: {gap}' for gap in info.get('preparation_gaps', [])]
        for entry in info['virtuals']:
            own = split_declaration(entry['declaration'])
            if own is None:
                continue
            for ancestor in ancestors({n: f['bases'] for n, f in facts.items()}, name):
                inherited = next((v for v in facts.get(ancestor, {}).get('virtuals', [])
                                  if v['slot'] == entry['slot']), None)
                if inherited and (parent := split_declaration(inherited['declaration'])):
                    if signature_key(own) != signature_key(parent):
                        conflicts.append(f'{name} slot {entry["slot"]}: signature differs from {ancestor}; '
                                         'verify locally before choosing a base declaration')
                    break
    for fn in functions:
        method = fn['name'].split('::')[-1]
        decl = next((v for v in facts.get(cls, {}).get('virtuals', []) if v['name'] == method), None)
        # A local exporter may supply this function's community signature/destructor metadata.
        pack = Path(fn['pack']) if fn.get('pack') else None
        readme = _text(pack / 'README.md') if pack else ''
        local_pack = _json(pack / 'pack.json') if pack else {}
        destructor = fn.get('destructor') or local_pack.get('destructor')
        if decl and 'Community declaration:' not in readme:
            readme += f'\nCommunity declaration: `{decl["declaration"]}`\n'
        info = facts.get(cls, {})
        members.append(dict(fn, community_name=fn['name'], pack_dir=pack, readme=readme, destructor=destructor,
                            pack_json={'identity': {'name_source': info.get('source') or fn.get('name_source')}}))
        hints += advice(repo, cls, method, decl['slot'] if decl else None)
        if decl and facts.get(cls, {}).get('bases'):
            hints += advice(repo, facts[cls]['bases'][0], method, decl['slot'])
    unit = {'cls': cls, 'area': area, 'header': f'reconstruction/{area}/{cls}.h',
            'compiled': f'reconstruction/{area}/{cls}.cpp', 'brief': '', 'material': [],
            'task': {'task_id': f'contrib-{cls.lower()}', 'build_id': functions[0]['build_id'], 'recipe': recipe},
            'functions': members, 'evidence': functions[0].get('evidence'), 'contributor': True, 'code_origin': code_origin,
            'community_facts': facts, 'signature_conflicts': conflicts,
            'notices': [n for n in notices if not any(n != other and n in other for other in notices)]}
    rendered = render_unit(unit, drafted_by, repo)
    return (*rendered, list(dict.fromkeys(hints + conflicts)), unit['task']['recipe'])


# ------------------------------------------------------------------ task directory inputs

def load_unit(task_dir, repo=None):
    """The facts a skeleton or sheet needs from a unit task directory and the packs it names."""
    repo = Path(repo or REPO)
    task_dir = Path(task_dir)
    try:
        task = json.loads((task_dir / 'task.json').read_text())
    except (OSError, ValueError) as exc:
        raise SkeletonError(f'{task_dir}: no readable task.json ({exc}); give a unit task directory, '
                            'not a group directory') from None
    compiled = task.get('compiled') or ''
    m = re.fullmatch(r'reconstruction/((?:[a-z][a-z0-9_]*/)*[a-z][a-z0-9_]*)/((?:hk[a-z]{0,2})?[A-Z][A-Za-z0-9_]*)\.cpp', compiled)
    if not m:
        raise SkeletonError(f'{task_dir}/task.json: compiled must be reconstruction/<area>/<Class>.cpp')
    brief_path = task_dir / 'BRIEF.md'
    brief = brief_path.read_text() if brief_path.is_file() else ''
    material = [Path(repo) / p for p in (task.get('export') or {}).get('class_material', [])]
    functions = []
    for f in task.get('functions') or []:
        pack = Path(repo) / f['pack'] if f.get('pack') else None
        functions.append(dict(f, pack_dir=pack, pack_json=_json(pack / 'pack.json') if pack else {},
                              readme=_text(pack / 'README.md') if pack else ''))
    return {'dir': task_dir, 'task': task, 'area': m.group(1), 'cls': m.group(2), 'compiled': compiled,
            'header': f'reconstruction/{m.group(1)}/{m.group(2)}.h', 'brief': brief,
            'material': material, 'functions': functions}


def _json(path):
    try:
        return json.loads(Path(path).read_text())
    except (OSError, ValueError):
        return {}


def _text(path):
    try:
        return Path(path).read_text()
    except OSError:
        return ''


def shared_path(repo, header, include):
    """Resolve an existing repository header, emitting only reconstruction-root include names."""
    repo = Path(repo).resolve()
    for path in ((repo / header).parent / include, repo / 'reconstruction' / include):
        path = path.resolve()
        if path.is_relative_to(repo / 'reconstruction') and path.is_file():
            return path
    return None


def header_text(path, repo, seen=None):
    """Declarations in a header's local include closure, for collision and size checks."""
    from reconstruction_includes import header_path
    seen = set() if seen is None else seen
    path = Path(path).resolve()
    if path in seen or not path.is_relative_to(Path(repo).resolve()) or not path.is_file():
        return ''
    seen.add(path)
    text = _text(path)
    includes = re.findall(r'^\s*#\s*include\s+"([^"\n]+)"', text, re.M)
    return text + '\n' + '\n'.join(header_text(target, repo, seen) for name in includes
                                         if (target := shared_path(repo, path.relative_to(Path(repo).resolve()), name)))


def class_defined(text, name):
    return bool(re.search(rf'\b(?:class|struct)\s+{re.escape(name)}\b[^;{{}}]*{{', text))


def brief_evidence(brief):
    m = re.search(r'Evidence: cite `((?:findings|reports)/[^`]+)`', brief)
    return m.group(1) if m else None


def brief_shared_headers(brief):
    """{class: include path} from the brief's "Shared headers" list."""
    return dict(re.findall(r'^- `(\w+)`: `#include "([^"]+)"`', brief, re.M))


def class_chain(material_dirs, cls):
    """(bases of each class, size of each class) from the class material's skeleton.h, which the
    pack export derives from the image RTTI and the operator delete size of each class."""
    bases, sizes = {}, {}
    for d in material_dirs:
        text = _text(Path(d) / 'skeleton.h')
        for m in re.finditer(r'^(?:class|struct)\s+(\w+)(?:\s*:\s*([^{\n]+))?\s*$', text, re.M):
            bases.setdefault(m.group(1), re.findall(r'(?:public|protected|private)\s+(?:virtual\s+)?:*(\w+)',
                                                    m.group(2) or ''))
        for m in re.finditer(r'static_assert\(sizeof\((\w+)\)\s*==\s*(0x[0-9A-Fa-f]+|\d+)', text):
            sizes.setdefault(m.group(1), int(m.group(2), 0))
    return bases, sizes


def ancestors(bases, cls):
    out, seen, cur = [], {cls}, cls
    while bases.get(cur):
        cur = bases[cur][0]
        if cur in seen:
            break
        seen.add(cur)
        out.append(cur)
    return out


def excerpt_label(material_dirs, packs):
    """Label of the community class declaration the pack quotes (its first line names the source)."""
    for d in list(material_dirs) + list(packs):
        first = _text(Path(d) / 'class-excerpt.h').split('\n', 1)[0]
        if first:
            label, _ = community_label(first)
            if label:
                return label
    return None


def community_declaration(fn, material_dirs, method):
    decl = re.search(r'Community declaration: `([^`]+)`', fn.get('readme') or '')
    if decl:
        return decl.group(1)
    for d in material_dirs:
        lines = _text(Path(d) / 'skeleton.h').splitlines()
        for i, line in enumerate(lines):
            if re.search(rf'//\s*\w+::{re.escape(method)}:', line) and i + 1 < len(lines):
                m = re.search(r'community declaration:\s*(.+)$', lines[i + 1])
                if m:
                    return m.group(1).strip()
    return None


# ------------------------------------------------------------------ declarations

def split_declaration(decl):
    """(return type, parameter text, trailing qualifiers, is virtual, is static) of a one-line
    community declaration, or None when it is not a plain function declaration."""
    code = re.sub(r'\[\[[^\]]*\]\]', ' ', decl.split('//', 1)[0])
    code = re.sub(r'\{.*\}\s*;?\s*$', '', code).strip().rstrip(';').strip()
    code = re.sub(r'\bRE::', '', code)
    code = re.sub(r'\bSKYRIM_REL_VR_VIRTUAL\b', '', code)
    # The pinned recipe is C++14; use byte-sized storage for C++17 byte pointer declarations.
    code = code.replace('std::byte', 'std::uint8_t')
    call_operator = re.search(r'\boperator\s*\(\s*\)\s*\(', code)
    open_ = call_operator.end() - 1 if call_operator else code.find('(')
    if open_ < 0:
        return None
    depth, close = 0, -1
    for i in range(open_, len(code)):
        depth += {'(': 1, ')': -1}.get(code[i], 0)
        if depth == 0:
            close = i
            break
    if close < 0:
        return None
    head, params, tail = code[:open_].strip(), code[open_ + 1:close].strip(), code[close + 1:]
    virtual = bool(re.search(r'\b(virtual|override)\b', code))
    static = bool(re.search(r'\bstatic\b', head))
    head = re.sub(r'\b(virtual|static|inline|constexpr|explicit)\b', ' ', head)
    words = head.split()
    if len(words) < 2:
        return None
    ret = ' '.join(words[:-1]).replace(' *', '*').replace(' &', '&')
    tail = re.sub(r'\b(override|final)\b|=\s*0\b|=\s*default\b|=\s*delete\b', ' ', tail)
    quals = ' '.join(tail.split())
    params = '' if params == 'void' else ' '.join(params.split())
    return ret, params, quals, virtual, static


def signature_key(parts):
    """Compare types/qualifiers, ignoring community parameter names and default values."""
    ret, params, quals, _virtual, _static = parts
    params = without_defaults(params)
    params = re.sub(r'\b[a-zA-Z_]\w*\s*(?=[,)]|$)',
                    lambda m: '' if m[0].strip().startswith('a_') else m[0], params)
    return tuple(re.sub(r'\s+', '', text) for text in (ret, params, quals))


def without_defaults(params):
    out, depth, cur = [], 0, ''
    for ch in params + ',':
        if ch in '(<':
            depth += 1
        elif ch in ')>':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur.split('=', 1)[0].strip())
            cur = ''
        else:
            cur += ch
    return ', '.join(p for p in out if p)


def base_constructor(text, base):
    """Parameters of the included base's first declared constructor when it has no default one
    (a derived constructor must then pass them on), else None."""
    found = [m.group(1).strip() for m in re.finditer(rf'^\s*(?:explicit\s+)?{re.escape(base)}\s*\(([^)]*)\)\s*;',
                                                     text, re.M)]
    if not found or any(f in ('', 'void') for f in found):
        return None
    return ' '.join(found[0].split())


def argument_names(params):
    return [re.findall(r'(\w+)\s*(?:\[[^\]]*\])?$', p.strip())[0] for p in without_defaults(params).split(',')
            if re.findall(r'(\w+)\s*(?:\[[^\]]*\])?$', p.strip())]


def type_names(text):
    """(names used through a pointer or reference, names used by value) in a declaration part."""
    by_ref, by_value = [], []
    for m in re.finditer(r'(?<![\w:])((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)(\s*[*&])?', text):
        name, indirect = m.group(1), m.group(2)
        first = name.split('::')[0]
        if first in BUILTIN or name.startswith('std::') or not (first[:1].isupper() or first.startswith('bhk')) or re.fullmatch(r'a_\w+', name):
            continue
        (by_ref if indirect else by_value).append(name)
    return by_ref, by_value


# ------------------------------------------------------------------ the skeleton

def method_of(fn, cls):
    name = fn.get('community_name') or ''
    method = name.split('::')[-1] if '::' in name else name
    if method in ('ctor', cls):
        return 'ctor'
    if method.startswith('~') or method in ('dtor', 'Destructor'):
        return 'dtor'
    if method == 'operator' and re.search(r'\boperator\s*\(\s*\)', fn.get('readme') or ''):
        return 'operator()'
    return method


def plan(unit, repo=None):
    """Everything both files say, computed once so the header and the source agree."""
    repo = Path(repo or REPO)
    cls, task = unit['cls'], unit['task']
    packs = [f['pack_dir'] for f in unit['functions'] if f.get('pack_dir')]
    bases, sizes = class_chain(unit['material'], cls)
    facts = unit.get('community_facts') or {}
    if facts:
        bases = {name: info['bases'] for name, info in facts.items()}
        sizes = {name: info['size'] for name, info in facts.items() if info.get('size') is not None}
    chain = ancestors(bases, cls)
    from reconstruction_includes import header_path
    shared = brief_shared_headers(unit['brief'])
    if not shared:
        shared = {p.stem: p.relative_to(Path(repo) / 'reconstruction').as_posix()
                  for anc in chain for p in sorted((Path(repo) / 'reconstruction').rglob(f'{anc}.h')) if p.stem != cls
                  and p.parent.name != 'declarations'}
    # For community-only preparation prefer the additive, complete-signature kit.
    if facts:
        shared.update({p.stem: p.relative_to(repo / 'reconstruction').as_posix()
                       for p in (repo / 'reconstruction/declarations').glob('*.h') if p.stem != cls})
    shared = {name: path.relative_to(repo / 'reconstruction').as_posix()
              for name, value in shared.items()
              if (path := shared_path(repo, unit['header'], value))}
    # The inline form needs the chain to end in NiObject -> NiRefObject, the only roots it writes.
    inline_base = (chain[-2:] == list(reversed(INLINE_BASE_ROOTS))
                   and any(inlines_ni_base(f) for f in unit['functions']))
    include, standins = None, []
    for anc in chain:
        ancestor_path = shared_path(repo, unit['header'], shared[anc]) if anc in shared else None
        included = header_text(ancestor_path, repo) if ancestor_path else ''
        asserted = re.search(rf'static_assert\(sizeof\({re.escape(anc)}\)\s*==\s*(0x[0-9a-fA-F]+|\d+)',
                             included)
        sized = asserted and (anc not in sizes or int(asserted.group(1), 0) == sizes[anc])
        if included and unit.get('contributor'):
            from contrib_screen import screen_tree
            try:
                if screen_tree(repo, ancestor_path.relative_to(repo).as_posix()):
                    included = ''
            except (ValueError, OSError):
                included = ''
        collisions = any(class_defined(included, name) for name in [cls] + standins)
        if (included and sized and not collisions and '// TODO type ' not in included and not inline_base):
            include = (anc, ancestor_path.relative_to(repo / 'reconstruction').as_posix())
            break
        standins.append(anc)
    if include is None:
        # No ancestor has a header (or the inline form needs every base local): the whole chain
        # becomes stand-ins up to its root.
        standins = list(chain)
    standins.reverse()
    included_text = ''
    if include:
        path = shared_path(repo, unit['header'], include[1])
        included_text = header_text(path, repo)
    elif inline_base:
        included_text = inline_base_blocks() + '\n'.join(f'class {t};' for t in INLINE_BASE_FORWARD)
    class_label = facts.get(cls, {}).get('label') or excerpt_label(unit['material'], packs)
    members = []
    for f in unit['functions']:
        ident = (f.get('pack_json') or {}).get('identity') or {}
        label, _ = community_label(ident.get('name_source'))
        method = method_of(f, cls)
        decl = None if method in ('ctor', 'dtor') else community_declaration(f, unit['material'], method)
        members.append({'fn': f, 'method': method, 'label': label, 'decl': decl,
                        'parts': split_declaration(decl) if decl else None})
        class_label = class_label or label
    # Repeated bare `dtor` names are not evidence that distinct RVAs are one C++ destructor.
    # Keep each address separately draftable without inventing subobject ownership or a signature.
    ambiguous = [m for m in members if m['method'] == 'dtor' and not m['fn'].get('destructor')]
    if len(ambiguous) > 1:
        for m in ambiguous:
            rva = m['fn']['rva']
            rva = int(rva, 16) if isinstance(rva, str) else rva
            m.update(method=f'UnknownDtor_{rva:x}', label=None)
    return {'cls': cls, 'task': task, 'chain': chain, 'bases': bases, 'sizes': sizes, 'include': include,
            'included_text': included_text, 'standins': standins, 'class_label': class_label,
            'inline_base': inline_base,
            'members': members, 'rtti': (bool(chain) or cls in sizes) and not facts, 'facts': facts}


def defined_in(text, name):
    return bool(re.search(rf'\b(?:class|struct|enum(?:\s+class|\s+struct)?|using|typedef)\s+{re.escape(name)}\b', text))


def skeleton_files(task_dir, drafted_by=None, repo=None):
    """(header path, header text, source path, source text) for a unit task directory."""
    repo = Path(repo or REPO)
    unit = load_unit(task_dir, repo)
    return render_unit(unit, drafted_by, repo)


def render_unit(unit, drafted_by=None, repo=None):
    """One renderer for internal tasks and the contributor adapter."""
    repo = Path(repo or REPO).resolve()
    code_origin = unit.get('code_origin')
    if code_origin is not None and (not code_origin.strip() or len(code_origin) > 2048
                                    or any(ord(c) < 32 for c in code_origin)):
        raise SkeletonError('code origin must be a nonempty single-line declaration')
    origin_lines = ([f'// Code origin: {code_origin or "SKELETON_TODO_CODE_ORIGIN (state the actual origin and any adaptation)"}']
                    if unit.get('contributor') or unit.get('contributor_origin') else [])
    p = plan(unit, repo)
    cls, build = p['cls'], unit['task'].get('build_id')
    task_id = unit['task'].get('task_id') or 'unit'
    recipe = unit['task'].get('recipe')
    if p['include']:
        recipe = root_include_recipe(repo, recipe)
        unit['task']['recipe'] = recipe
    evidence = unit.get('evidence') or brief_evidence(unit['brief'])
    labels = {}  # label text -> names, in first-seen order

    def add(names, label):
        labels.setdefault(label, [])
        for n in names if isinstance(names, list) else [names]:
            if n not in labels[label]:
                labels[label].append(n)

    if p['class_label']:
        add(cls, p['class_label'] + (' EXE_RTTI' if p['rtti'] else ''))
    elif p['rtti']:
        add(cls, 'EXE_RTTI')
    else:
        add(cls, 'GUESS(low)')
    for s in p['standins']:
        if not (p['inline_base'] and s in INLINE_BASE_ROOTS):  # those blocks carry their own labels
            add(s, 'STANDIN ' + (p['facts'].get(s, {}).get('label')
                                 or ('GUESS(low)' if unit.get('contributor') else 'EXE_RTTI')))

    forward, todo_types, decls, defs, notes = [], [], [], [], []
    nested_forward = {}
    event_types = set()
    has_ctor = any(m['method'] == 'ctor' for m in p['members'])
    has_dtor = any(m['method'] == 'dtor' for m in p['members'])
    ctor_params = base_constructor(p['included_text'], p['include'][0]) if p['include'] else None
    if has_dtor and not has_ctor:
        params = ctor_params or ''
        init = ''
        if ctor_params:
            direct = p['standins'][-1] if p['standins'] else p['include'][0]
            init = f'\n    : {direct}({", ".join(argument_names(ctor_params))})'
        decls.append(f'{cls}({params});')
        defs.append('\n'.join([
            '// Not compared: defined so that the compiler emits the vftable and, beside it, the',
            '// deleting destructor that is compared (cookbook rule 14).',
            f'{cls}::{cls}({without_defaults(params)}){init}',
            '{',
            '}']))
    for m in p['members']:
        f, method = m['fn'], m['method']
        rva, size = int(str(f['rva']), 16) if isinstance(f['rva'], str) else f['rva'], f['size']
        where = f'RVA 0x{rva:x}, {size} bytes, {f.get("community_name")}'
        kind = (f.get('destructor') or {}).get('kind')
        if method == 'ctor':
            if m['label']:
                # Labelled under the name the community source gives the function (meh321's list
                # calls constructors `ctor`), which is the name check_labels.py can find there.
                add(f'{f.get("community_name")}', m['label'])
            decls.append(f'{cls}();  // compared: 0x{rva:x}')
            head = f'{cls}::{cls}()'
        elif method == 'dtor':
            if m['label']:
                add(f'{cls}::~{cls}', m['label'])
            decls.append(f'virtual ~{cls}();  // compared: 0x{rva:x}' + (f' ({kind})' if kind else ''))
            head = f'{cls}::~{cls}()'
            if kind and 'deleting' in kind and p['inline_base']:
                where += (f'; compared as the {kind}. The target does the NiRefObject cleanup itself, so keep '
                          'this empty definition and the constructor: the inline base destructors in the header '
                          'make the compiler produce the same body')
            elif kind and 'deleting' in kind:
                where += (f'; compared as the {kind}. If the target calls a separate destructor, keep only '
                          'the declaration and delete this definition (cookbook rule 18)')
        elif m['parts']:
            ret, params, quals, virtual, static = m['parts']
            if m['label']:
                add(f'{cls}::{method}', m['label'])
            prefix = 'static ' if static else 'virtual ' if virtual else ''
            decls.append(f'{prefix}{ret} {method}({params}){" " + quals if quals else ""};  // compared: 0x{rva:x}')
            head = f'{ret} {cls}::{method}({without_defaults(params)}){" " + quals if quals else ""}'
            by_ref, by_value = type_names(f'{ret} ({params})')
            for t in SUPPORT_DECLARATIONS:
                if t in by_ref + by_value and not defined_in(p['included_text'], t):
                    event_types.add(t)
                    add(t, 'STANDIN ' + _NG)
                    if t == 'EffectArchetype':
                        add(['EffectArchetypes', 'EffectArchetypes::ArchetypeID'], 'STANDIN ' + _NG)
            for t in by_ref:
                if t in event_types:
                    continue
                if '::' in t:
                    outer, _, inner = t.partition('::')
                    if outer in [cls] + p['standins'] and '::' not in inner:
                        nested_forward.setdefault(outer, set()).add(inner)
                        add(t, 'STANDIN ' + (m['label'] or _NG))
                    else:
                        todo_types.append((t, 'nested type: declare a stand-in for it or change the type'))
                elif (t != cls and t not in forward and not defined_in(p['included_text'], t)
                      and t not in (INLINE_BASE_FORWARD if p['inline_base'] else ())):
                    forward.append(t)
                    if m['label']:
                        add(t, 'STANDIN ' + m['label'])
            for t in by_value:
                if (t != cls and t not in event_types and t not in forward
                        and not defined_in(p['included_text'], t) and t not in (x for x, _ in todo_types)):
                    todo_types.append((t, 'used by value: declare it (an enum or a small class) before the class'))
        else:
            if m['label']:
                add(f'{cls}::{method}', m['label'])
            else:
                add(f'{cls}::{method}', 'GUESS(low)')
            decls.append(f'void {method}();  // compared: 0x{rva:x}; TODO signature: no community declaration, '
                         'read it from the listing')
            head = f'void {cls}::{method}()'
        complete_form = (f.get('destructor') or {}).get('complete_form')
        if method == 'dtor' and kind and 'deleting' in kind and complete_form == 'out-of-line':
            # Keep only the declaration: the emitted deleting wrapper calls the complete dtor.
            continue
        if method == 'dtor' and kind and 'deleting' in kind and (p['inline_base'] or complete_form == 'inline'):
            # Nothing to write: the empty body plus the inline bases is the accepted form.
            defs.append('\n'.join([*comment_lines(f'Body done: {where}.'), head, '{', '}']))
            continue
        defs.append('\n'.join([*comment_lines(f'TODO body: {where}.'), head, '{', f'    {BODY_MARKER};', '}']))

    # Keep every community virtual, in slot order, including un-compared declarations. This
    # prevents a first contributed override from accidentally becoming slot zero of a new type.
    def complete_virtuals(name, compared):
        info = p['facts'].get(name, {})
        ordered = []
        remaining = list(compared)
        for entry in sorted(info.get('virtuals', []), key=lambda v: v['slot']):
            method = entry['name']
            selected = next((d for d in remaining if re.search(rf'(?<!\w){re.escape(method)}\s*\(', d)), None)
            if selected:
                remaining.remove(selected)
                ordered.append(selected + f'  // slot {entry["slot"]:02X}')
            else:
                declaration = re.sub(r'\b(?:override|final)\b\s*', '', entry['declaration'])
                if not re.search(r'\bvirtual\b', declaration):
                    declaration = 'virtual ' + declaration
                ordered.append(declaration + f'  // {entry["slot"]:02X}')
                add(f'{name}::{method}', info['label'])
            # Reference declarations for non-compared slots need the same preparation too.
            parts = split_declaration(entry['declaration'])
            refs, values = type_names(f'{parts[0]} ({parts[1]})') if parts else ([], [])
            for t in refs:
                if t in [cls] + p['standins'] or defined_in(p['included_text'], t):
                    continue
                if t in SUPPORT_DECLARATIONS:
                    event_types.add(t)
                    add(t, 'STANDIN ' + info['label'])
                elif '::' not in t and t not in forward:
                    forward.append(t)
                    add(t, 'STANDIN ' + info['label'])
            for t in values:
                if (t in [cls, name] or t in SUPPORT_DECLARATIONS or defined_in(p['included_text'], t)
                        or t in (x for x, _ in todo_types)):
                    continue
                todo_types.append((t, 'used by value: supply a permitted declaration before compiling'))
        return ordered + remaining

    if p['facts']:
        decls = complete_virtuals(cls, decls)

    # Stand-ins and the class itself, padded to the image sizes so offsets line up from the start.
    pads, blocks = [], []
    parent = p['include'][0] if p['include'] else None
    # Size of the class built so far: a stand-in without a known image size adds nothing, so its
    # derived class pads from the nearest known size below it.
    running = p['sizes'].get(parent) if parent else 0x8
    for s in p['standins']:
        if p['inline_base'] and s in INLINE_BASE_ROOTS:
            if s == INLINE_BASE_ROOTS[-1]:
                block = inline_base_blocks()
                blocks.append(block.replace(' EXE_RTTI', '') if unit.get('contributor') else block)
            parent, running = s, 0x10
            continue
        body, assert_line, running = pad_lines(s, running, p['sizes'], pads)
        base = f' : public {parent}' if parent else ''
        inherit = [f'    using {parent}::{parent};'] if ctor_params and parent else []
        vptr = ([f'    {d}' for d in complete_virtuals(s, [])] if p['facts'].get(s) else
                [f'    virtual ~{s}() = default;'] if parent is None else [])
        if vptr and not p['facts'].get(s):
            add(f'{s}::~{s}', 'GUESS(low)')
        nested = [f'    struct {n};' for n in sorted(nested_forward.get(s, ()))]
        blocks.append('\n'.join([f'class {s}{base}', '{', 'public:', *nested, *inherit, *vptr, *body, '};', *assert_line, '']))
        parent = s
    body, assert_line, running = pad_lines(cls, running, p['sizes'], pads)
    base = f' : public {parent}' if parent else ''
    nested = [f'    struct {n};' for n in sorted(nested_forward.get(cls, ()))]
    cls_block = [f'class {cls}{base}', '{', 'public:', *nested, *[f'    {d}' for d in decls]]
    if parent is None and not any(d.startswith('virtual ') for d in decls) and p['rtti']:
        cls_block.append('    void* unknown00;  // primary vftable storage')
        pads.append('unknown00')
    if body:
        cls_block += ['', '    // TODO members: replace part of the padding with the members the bodies read,',
                      '    // keeping every offset and the size check true.', *body]
    cls_block += ['};', *assert_line, '']
    if pads:
        add(pads, 'GUESS(low)')

    gpl = any(is_gpl(label) for label in labels)
    label_lines = [f'// {", ".join(names)}: {label}' for label, names in labels.items() if names]
    from declaration_kit import GPL_NOTICE
    from lint_reconstruction import SPDX_CC0, SPDX_MIT
    notices = list(unit.get('notices', []))
    for text, needed in ((SPDX_MIT, p['inline_base'] or any('CommonLibSSE' in label for label in labels)),
                         (GPL_NOTICE, gpl)):
        notice_text = '\n'.join('// ' + line if line else '//' for line in text.splitlines())
        if needed and not any(notice_text in n for n in notices):
            notices.append(notice_text)
    if not gpl and not any('SPDX-License-Identifier' in n for n in notices):
        notices.insert(0, '// ' + SPDX_CC0)
    header = [
        ('// Source exposure: mixed (community headers; compared functions from the pinned image).'
         if not p['facts'] else '// Source exposure: mixed (community declarations and the contributor-owned pack).'),
        *origin_lines,
        *([GPL_NOTE] if gpl else []),
        *notices,
        *base_form_lines(p),
        *label_lines,
        '#pragma once',
        '',
        *(['// Atomic lifetime counting uses the compiler intrinsic for one shared counter.',
           'extern \"C\" long _InterlockedDecrement(volatile long*);'] if p['inline_base'] else []),
        '#include <cstdint>',
        '#include <cstddef>',
    ]
    if p['include']:
        header.append(f'#include "{p["include"][1]}"')
    header.append('')
    if unit.get('contributor'):
        for name in p['standins']:
            if name not in p['facts']:
                header += comment_lines(f'SKELETON_TODO_BASE_SIGNATURE: {name} has no prepared virtual declarations.')
    for conflict in unit.get('signature_conflicts', []):
        header += comment_lines('SKELETON_TODO_SIGNATURE: ' + conflict)
    if p['inline_base']:
        header += [f'class {t};' for t in INLINE_BASE_FORWARD] + ['']
    if forward:
        reference_kinds = {name: kind for info in p['facts'].values()
                           for name, kind in info.get('reference_kinds', {}).items()}
        header += [f'{reference_kinds.get(t, "class")} {t};' for t in forward] + ['']
    for t in sorted(event_types):
        header += [SUPPORT_DECLARATIONS[t], '']
    for t, why in todo_types:
        header.append(f'// TODO type {t}: {why}.')
    if todo_types:
        header.append('')
    extra_bases = p['bases'].get(cls, [])[1:]
    if extra_bases:
        header += [f'// TODO bases: the available class context also lists {", ".join(extra_bases)} after the first base; add them '
                   'in that order if a compared function needs them (cookbook rule 25).', '']
    header += blocks + cls_block

    compared = [f'// 0x{(int(str(m["fn"]["rva"]), 16) if isinstance(m["fn"]["rva"], str) else m["fn"]["rva"]):x} '
                f'{m["fn"].get("community_name")}' for m in p['members']]
    source = [
        '// Source exposure: mixed (community headers; the pinned image listing).',
        *origin_lines,
        *([GPL_NOTE] if gpl else []),
        *notices,
        *([f'// Recipe: {recipe}'] if recipe != DEFAULT_RECIPE else []),
        *compared,
        f'// Adapted bodies: {ORIGIN_MARKER} (write "none" when attempt prints no "origin advice" line;',
        '// otherwise name each adapted body, its upstream file, revision and licence).',
        f'#include "{cls}.h"',
        '',
        '\n\n'.join(defs),
        '',
    ]
    return unit['header'], '\n'.join(header), unit['compiled'], '\n'.join(source)


def base_form_lines(p):
    """Header comment lines saying which base form the skeleton chose, and why."""
    if p['inline_base']:
        return comment_lines('Base form: inline stand-ins. The compared deleting destructor does the NiRefObject '
                             'cleanup itself (it stores that vftable and decrements the object counter), so '
                             'NiRefObject and NiObject are declared here with inline destructors instead of '
                             'including the shared NiObject.h, whose out-of-line destructors would add a call.')
    if p['include']:
        return comment_lines(f'Base form: shared header {p["include"][1]} for {p["include"][0]}.')
    return comment_lines('Base form: local stand-ins (no ancestor has a shared header).') if p['standins'] else []


def comment_lines(text, width=100):
    return ['// ' + line for line in textwrap.wrap(text, width - 3, break_long_words=False, break_on_hyphens=False)]


def pad_lines(cls, start, sizes, pads):
    """(padding member lines, size check lines, size after this class) for a stand-in or the unit's
    class; `start` is the size of the class below it, None when unknown."""
    size = sizes.get(cls)
    if size is None:
        return [], [], start
    if start is None or size < start:
        return [], [], None
    if size == start:
        return [], [f'static_assert(sizeof({cls}) == 0x{size:X}, "{cls} size");'], size
    # Not unkNN or padNN: the community headers use those spellings for real members, and a made-up
    # name that collides with one reads as a mislabelled community name.
    name = f'unknown{start:02X}'
    pads.append(name)
    return ([f'    std::uint8_t {name}[0x{size - start:X}];  // {start:02X}'],
            [f'static_assert(sizeof({cls}) == 0x{size:X}, "{cls} size");'], size)


def write_skeleton(task_dir, drafted_by=None, repo=None):
    """Write both files; refuse when either exists. Returns the two repository paths."""
    repo = Path(repo or REPO)
    h_rel, h_text, cpp_rel, cpp_text = skeleton_files(task_dir, drafted_by, repo)
    existing = [rel for rel in (h_rel, cpp_rel) if (Path(repo) / rel).exists()]
    if existing:
        raise SkeletonError(f'{" and ".join(existing)} already exist{"s" if len(existing) == 1 else ""}; '
                            'not overwritten. Edit the existing files, or move them to '
                            f'{Path(task_dir).as_posix()}/near-miss/ first if you want a fresh start.')
    for rel, text in ((h_rel, h_text), (cpp_rel, cpp_text)):
        path = Path(repo) / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        with open(path, 'x') as out:  # 'x': never replace a file created since the check above
            out.write(text)
    task_path = Path(task_dir) / 'task.json'
    task = _json(task_path)
    recipe = re.search(r'^// Recipe: (\S+)', cpp_text, re.M).group(1)
    if task.get('recipe') != recipe:
        task['recipe'] = recipe
        task_path.write_text(json.dumps(task, indent=2) + '\n')
    p = plan(load_unit(task_dir, repo), repo)
    hints = {f'{p["cls"]}::{m["method"]}': m['fn']['rva'] for m in p['members']
             if m['method'].startswith('UnknownDtor_') or m['method'] == 'operator()'}
    if hints:
        hint_path = Path(task_dir) / 'bind-hints.json'
        previous = _json(hint_path)
        hint_path.write_text(json.dumps(dict(hints, **previous), indent=2) + '\n')
    return h_rel, cpp_rel


# ------------------------------------------------------------------ the sheet

def readme_section(readme, title):
    m = re.search(rf'^## {re.escape(title)}[^\n]*\n(.*?)(?=^## |\Z)', readme or '', re.S | re.M)
    return m.group(1).strip() if m else ''


def brief_rules(brief):
    m = re.search(r'Cookbook rules these listings point to[^\n]*\n((?:- [^\n]*\n?)+)', brief)
    return m.group(1).strip() if m else ''


def brief_sibling(brief):
    m = re.search(r'^#+ Sibling source[^\n]*\n(.*?)(?=^#+ |\Z)', brief, re.S | re.M)
    if not m:
        return ''
    keep = [line for line in m.group(1).splitlines() if line.startswith('- ') or line.startswith('Small named')]
    return '\n'.join(keep)


def sibling_snippet(brief, rva, repo=None, limit=40):
    """The FNV body of the same-named method the brief points to for `rva`, up to `limit` lines."""
    repo = Path(repo or REPO)
    m = re.search(rf'^- `0x{rva:x}`: `[^`]+` `((?:src|include)/[^`:]+):(\d+)`', brief, re.M)
    if not m:
        return ''
    rel = PurePosixPath(m.group(1))
    if '..' in rel.parts:
        return ''
    lines = _text(Path(repo) / '.local/sources/fnv_decomp' / rel).splitlines()
    start = int(m.group(2)) - 1
    out, depth, opened = [], 0, False
    for line in lines[start:start + limit]:
        out.append(line)
        depth += line.count('{') - line.count('}')
        opened = opened or '{' in line
        if opened and depth <= 0:
            break
    return '\n'.join(out)


def function_sheet(unit, fn, sibling=False, repo=None):
    repo = Path(repo or REPO)
    rva = int(str(fn['rva']), 16) if isinstance(fn['rva'], str) else fn['rva']
    readme = fn.get('readme') or ''
    pack = fn.get('pack_dir')
    kind = (fn.get('destructor') or {}).get('kind')
    symbol = fn.get('symbol') or ''
    out = [f'# 0x{rva:x} {fn.get("community_name")} ({fn["size"]} bytes)', '',
           f'Unit: {unit["compiled"]} (+ .h). Task dir: {display_task_dir(unit["dir"], repo)}.',
           f'Compared symbol: {"not bound yet (attempt binds it from your object)" if symbol.startswith("unbound:") else symbol}.']
    if kind:
        out.append(f'Kind: {kind} (the slot-0 body, `??_G`; cookbook rules 14 and 18).')
    cautions = (fn.get('pack_json') or {}).get('cautions') or []
    if cautions:
        out.append('Cautions: ' + '; '.join(cautions) + '.')
    # Earlier give-ups come first: they are what the last drafters learned, and a repeat of their tries is wasted.
    import giveup
    earlier = giveup.lines_for(repo, [rva])
    if earlier:
        out += [''] + earlier
    conv = readme_section(readme, 'Calling and return convention')
    conv = '\n'.join(line for line in conv.splitlines() if line.startswith('- '))
    out += ['', '## Signature and registers', conv or '- No community declaration; derive the signature from the listing.']
    refs = readme_section(readme, 'References leaving the function')
    refs = '\n'.join(line for line in refs.splitlines() if line.startswith('|'))
    out += ['', '## Calls and data it references (bind names to these RVAs only)', refs or '- none']
    mem = readme_section(readme, 'Observed memory operands (non-stack)')
    mem = '\n'.join(line for line in mem.splitlines() if line.startswith('|'))
    if mem:
        out += ['', '## Memory operands (offsets from the register; RCX is `this` at entry)', mem]
    rules = brief_rules(unit['brief'])
    if rules:
        out += ['', '## Cookbook rules the brief names for this unit', rules]
    sib = brief_sibling(unit['brief'])
    if sib and sibling:
        out += ['', '## Sibling (FNV; shape and names only, never offsets; label SIBLING if you take a name)', sib]
        snippet = sibling_snippet(unit['brief'], rva, repo) if sibling else ''
        if snippet:
            out += ['', '```cpp', snippet, '```']
    from fo4_private import INDEX as FO4_INDEX, hint_section
    from local_paths import local_dir
    if sibling and (local_dir(repo) / FO4_INDEX).is_dir():
        build_id = (unit.get('task') or {}).get('build_id')
        if not build_id:
            build_id = json.loads((repo / 'builds/target.json').read_text())['build_id']
        hint = hint_section(repo, build_id, rva)
        if hint:
            out += ['', hint]
    # Column padding is trailing blanks; dropping it keeps more of the listing on one page.
    listing = '\n'.join(line.rstrip() for line in _text(pack / 'listing.txt').splitlines()).strip() if pack else ''
    out += ['', '## Target listing', '```', listing or '(no listing in the pack)', '```']
    decomp = _text(pack / 'decompiled.c').rstrip() if pack else ''
    if decomp:
        out += ['', '## Decompiler output (a hint; often wrong in details)', '```c', decomp, '```']
    return '\n'.join(out) + '\n'


def paginate(text, cap=SHEET_CAP):
    """Pages of at most `cap` characters, cut at line ends (a longer line is cut inside)."""
    pages, cur = [], ''
    for line in text.splitlines(keepends=True):
        while len(line) > cap:
            if cur:
                pages.append(cur)
                cur = ''
            pages.append(line[:cap])
            line = line[cap:]
        if len(cur) + len(line) > cap:
            pages.append(cur)
            cur = ''
        cur += line
    if cur or not pages:
        pages.append(cur)
    return pages


def find_function(unit, rva_text):
    try:
        rva = int(rva_text, 16)
    except ValueError:
        raise SkeletonError(f'{rva_text} is not an RVA like 0x4aa860') from None
    for f in unit['functions']:
        if (int(str(f['rva']), 16) if isinstance(f['rva'], str) else f['rva']) == rva:
            return f
    listed = ', '.join(str(f['rva']) for f in unit['functions'])
    raise SkeletonError(f'0x{rva:x} is not a function of this unit (its functions: {listed})')


# Room kept on every page for the "page N of M" footer.
FOOTER_ROOM = 300


def sheet_pages(task_dir, rva_text, sibling=False, cap=SHEET_CAP, repo=None):
    repo = Path(repo or REPO)
    unit = load_unit(task_dir, repo)
    fn = find_function(unit, rva_text)
    return paginate(function_sheet(unit, fn, sibling, repo), cap - FOOTER_ROOM)


def display_task_dir(task_dir, repo):
    path = Path(task_dir)
    return (path.relative_to(repo) if path.is_absolute() and path.is_relative_to(repo) else path).as_posix()


def overview(task_dir, cap=SHEET_CAP, repo=None):
    """The unit's one-page index: files, functions and the command for each function's sheet."""
    repo = Path(repo or REPO)
    unit = load_unit(task_dir, repo)
    kind = unit['task'].get('drafter_kind') or ('normal' if any(
        f['size'] > 64 for f in unit['functions']) else 'small')
    d = display_task_dir(task_dir, repo)
    lines = [f'# Unit {unit["cls"]} ({unit["task"].get("task_id")})', '',
             f'Files: {unit["header"]} and {unit["compiled"]}. Budget: {unit["task"].get("max_attempts")} counted attempts.',
             f'Unit kind: {kind}. Card: docs/drafter-card-{kind}.md.',
             'Keep going while matching bytes rise; stop after the brief/profile N attempts with no improvement '
             'over the best score, or the hard attempt budget. The first mismatch may stay put.',
             '', '| RVA | bytes | name | sheet pages |', '|---|---|---|---|']
    for f in unit['functions']:
        n = len(paginate(function_sheet(unit, f, repo=repo), cap - FOOTER_ROOM))
        lines.append(f'| {f["rva"]} | {f["size"]} | {f.get("community_name")} | {n} |')
    import giveup
    earlier = [(f['rva'], giveup.brief(repo, f['rva'])) for f in unit['functions']]
    earlier = [f'- {rva}: {text}' for rva, text in earlier if text]
    if earlier:
        lines += ['', 'Earlier give-ups (the sheet of each function lists them first):'] + earlier
    lines += ['', f'Read one function: python3 tools/sheet.py {d} --function <rva> [--page N]']
    return '\n'.join(lines) + '\n'


SHEET_VARIANTS = {False: '.md', True: '.fnv.md'}


def sheet_name(rva, page, pages, sibling):
    """File name of one sheet page: sheet-0x<rva>[-p<N>].md, or .fnv.md for the FNV variant."""
    stem = f'sheet-0x{rva:x}' if pages == 1 else f'sheet-0x{rva:x}-p{page}'
    return stem + SHEET_VARIANTS[bool(sibling)]


def is_variant(path, sibling):
    return path.name.endswith('.fnv.md') == bool(sibling)


def write_sheets(task_dir, sibling=False, cap=SHEET_CAP, repo=None):
    """sheet.md (the index) and sheet-<rva>[-p<N>].md for each function, all in the task directory.

    With `sibling` the FNV variant is written instead (sheet.fnv.md, sheet-<rva>.fnv.md: the same
    pages plus the FNV body of a same-named method). The two variants live side by side because
    not every model that drafts from one queue is cleared to read FNV text; `sheets.json` records
    which variants exist so a runbook or a check can tell them apart. Returns the files written."""
    repo = Path(repo or REPO)
    unit = load_unit(task_dir, repo)
    d = Path(task_dir)
    for old in d.glob('sheet*.md'):
        if is_variant(old, sibling):
            old.unlink()
    index = d / ('sheet' + SHEET_VARIANTS[bool(sibling)])
    written = [index]
    index.write_text(overview(task_dir, cap, repo))
    for f in unit['functions']:
        rva = int(str(f['rva']), 16) if isinstance(f['rva'], str) else f['rva']
        pages = paginate(function_sheet(unit, f, sibling, repo), cap - FOOTER_ROOM)
        for i, page in enumerate(pages, 1):
            name = sheet_name(rva, i, len(pages), sibling)
            nxt = (f'\n(page {i} of {len(pages)}; next: {sheet_name(rva, i + 1, len(pages), sibling)})\n'
                   if i < len(pages) else (f'\n(page {i} of {len(pages)}, last)\n' if len(pages) > 1 else ''))
            (d / name).write_text(page + nxt)
            written.append(d / name)
    record = _json(d / 'sheets.json') or {}
    record.setdefault('variants', {})['fnv' if sibling else 'plain'] = {
        'sibling_snippets': bool(sibling), 'files': [w.name for w in written]}
    (d / 'sheets.json').write_text(json.dumps(record, indent=2, sort_keys=True) + '\n')
    return written


def write_sheet_variants(task_dir, which=None, cap=SHEET_CAP, repo=None):
    """Write the variants `which` asks for: None both, False the plain one, True the FNV one."""
    out = []
    for sibling in ((False, True) if which is None else (bool(which),)):
        out += write_sheets(task_dir, sibling, cap, repo)
    return out
