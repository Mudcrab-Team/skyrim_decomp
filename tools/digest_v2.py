"""tu-sha256-v2, the translation-unit digest that ignores prose comments, and the rules for reading records of either method.

v1 (tools/source_digest.py) hashes the raw bytes of every file of the unit, so any edit to a
comment makes every accepted record and review of the unit stale. v2 hashes each file with its
comments removed except the ones that carry provenance (`strip_comments`), so headers and prose can
be trimmed without reopening a match, while a changed name-origin label, exposure statement or
sibling citation still changes the revision. Strings and code are hashed as written.

v2 is also independent of file paths: each file is hashed without its name, files are taken in
include order, every repository `#include` is hashed as a fixed token, and the include edges are
hashed as (from-hash, to-hash, position). Moving or renaming files and rewriting the include lines
changes no digest; `__FILE__`, `__FILEW__` and `#line` are refused because they would put a path
into the code.

This is a separate module on purpose: the comparator's own version hash covers
tools/source_digest.py, so changing that file would make every recorded comparator report read as
produced by another comparator. v1 therefore stays there, byte for byte, and this module delegates
to it for v1.

A record's source states `digest_method` and `digest`. A record migrated from v1 also keeps
`run_digest_method` and `run_digest`, the v1 digest of the source its comparator runs were made on
(the runs embed it as their source revision); migration only writes it for a record whose v1
digest equalled the tree it was migrated from.

    python3 tools/digest_v2.py [--method tu-sha256-v1] reconstruction/x/A.cpp reconstruction/x/A.h
"""
import hashlib
import posixpath
from pathlib import Path, PurePosixPath
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import source_digest as v1  # noqa: E402
from source_digest import BLANKS, _refuse, logical_lines  # noqa: E402

DIGEST_METHODS = ('tu-sha256-v1', 'tu-sha256-v2')
DIGEST_METHOD = 'tu-sha256-v2'
# The tokens tools/lint_reconstruction.py and tools/check_labels.py read out of comments. A comment
# holding one is provenance and stays in the v2 digest; the label lint imports LABEL_WORD from here
# so the two cannot drift.
LABEL_WORD = re.compile(r'(?<![A-Za-z0-9_])(?:COMMUNITY|SIBLING|CRASHLOGGER_PDB|SYMBOLS|GUESS|EXE_RTTI|STANDIN|OBSERVED)[A-Za-z0-9_]*'
                        r'|(?<![A-Za-z0-9_])(?:EXE[- ]RTTI|STAND[- _]IN)(?![A-Za-z0-9_])')
PROVENANCE_FIELD = re.compile(r'Source exposure|Code origin|Adapted bod|Sibling source|Declaration source|'
                              r'Community source|Body origin|Inferred names|Licence:|License:')
CHAR_PREFIXES = {'L', 'u', 'U', 'u8'}


def is_provenance(comment):
    return bool(LABEL_WORD.search(comment) or PROVENANCE_FIELD.search(comment))


def strip_comments(blob, name, keep_provenance=True):
    """The file's text with every comment removed except provenance comments, as tu-sha256-v2 hashes it.

    `keep_provenance=False` removes those too, leaving only what the compiler sees (see `same_code`).

    Strings and character literals are copied as written and code is untouched. A removed `//`
    comment leaves nothing and a removed block comment one space; a line that held a removed
    comment loses its trailing blanks and, if nothing is left, disappears, so deleting a whole
    comment line changes no digest. A comment that holds a provenance token stays whole.
    Anything the scan cannot classify (a digit separator, an unterminated literal or comment,
    __LINE__, which would make line numbers part of the code) is refused: v1 stays available.
    """
    text = '\n'.join(logical_lines(blob, name))
    if '__LINE__' in text or '__COUNTER__' in text:
        _refuse(name, '__LINE__ or __COUNTER__ makes comment removal change the code')
    out, lines, touched = [], [], False
    i, n = 0, len(text)

    def flush():
        nonlocal out, touched
        line = ''.join(out)
        out, was = [], touched
        touched = False
        if was:
            line = line.rstrip(BLANKS)
            if not line:
                return
        lines.append(line)

    while i < n:
        c = text[i]
        if c == '\n':
            flush()
            i += 1
        elif c == '/' and text.startswith('//', i):
            end = text.find('\n', i)
            end = n if end < 0 else end
            if keep_provenance and is_provenance(text[i:end]):
                out.append(text[i:end])
            else:
                touched = True
            i = end
        elif c == '/' and text.startswith('/*', i):
            end = text.find('*/', i + 2)
            if end < 0:
                _refuse(name, 'unterminated block comment')
            body = text[i:end + 2]
            if keep_provenance and is_provenance(body):
                for k, part in enumerate(body.split('\n')):
                    if k:
                        flush()
                    out.append(part)
            else:
                out.append(' ')
                touched = True
            i = end + 2
        elif c in '"\'':
            if c == "'":
                before = ''.join(out)
                m = re.search(r'[A-Za-z0-9_]+$', before)
                if m and m.group(0)[0].isdigit():
                    out.append(c)  # digit separator inside a numeric literal
                    i += 1
                    continue
                if m and m.group(0) not in CHAR_PREFIXES:
                    _refuse(name, 'unclassifiable quote')
            j = i + 1
            while j < n and text[j] != c:
                if text[j] == '\n':
                    _refuse(name, 'unterminated string or character literal')
                j += 2 if text[j] == '\\' else 1
            if j >= n:
                _refuse(name, 'unterminated string or character literal')
            out.append(text[i:j + 1])
            i = j + 1
        else:
            out.append(c)
            i += 1
    flush()
    return '\n'.join(lines)


def same_code(old, new, name):
    """Whether two versions of a file differ only in comments, provenance labels included.

    False when either text cannot be classified by the comment scan, so only a change that cannot
    reach the compiler counts as comment-only.
    """
    try:
        return strip_comments(old, name, False) == strip_comments(new, name, False)
    except ValueError:
        return False


QUOTED_INCLUDE = re.compile(r'^([ \t]*#[ \t]*include[ \t]*)"([^"\n]+)"', re.M)


def _spelled_by_target(text, name, exists):
    """`text` with each quoted include rewritten to the repository file it reaches.

    A target is searched next to the including file, then from the repository's `reconstruction/`
    root; one that reaches no file stays as written, so a changed or broken include still differs.
    """
    own = posixpath.dirname(name)

    def reach(match):
        target = match.group(2)
        for base in (own, 'reconstruction'):
            found = posixpath.normpath(posixpath.join(base, target))
            if exists(found):
                return f'{match.group(1)}"{found}"'
        return match.group(0)
    return QUOTED_INCLUDE.sub(reach, text)


def same_code_resolved(old, new, name, exists):
    """Whether two versions of a file differ only in comments and in how a repository include is spelled.

    `exists(path)` says whether a repository file is present in the tree the new text lives in. The
    digest v2 maps every repository include to a fixed token, so such a change leaves every unit
    digest as it was; this is what lets the owner lane merge a respelling without a compile.
    """
    try:
        return (_spelled_by_target(strip_comments(old, name, False), name, exists)
                == _spelled_by_target(strip_comments(new, name, False), name, exists))
    except ValueError:
        return False


REPO_INCLUDE = '#include @repo'
FORBIDDEN_V2 = re.compile(r'(?<![A-Za-z0-9_])__FILEW?__(?![A-Za-z0-9_])|^[ \t]*#[ \t]*line\b', re.M)


def _resolve(name, target, kind, names, dirs):
    """The unit file an include of `name` reaches, None for a toolchain header; refuses what it cannot place."""
    own = PurePosixPath(name).parent
    tiers = ([[own]] if kind == '"' else []) + [[PurePosixPath(r) for r in v1.INCLUDE_ROOTS]]
    if kind == '"':
        tiers.append([d for d in dirs if d != own])
    for tier in tiers:
        hits = {posixpath.normpath((base / target).as_posix()) for base in tier}
        hits &= names
        if len(hits) == 1:
            return hits.pop()
        if len(hits) > 1:
            _refuse(name, f'#include "{target}" is ambiguous inside the unit')
    if kind == '"':
        _refuse(name, f'#include "{target}" is not a file of the unit')
    return None


def _unit_digest_v2(blobs):
    """Path-independent digest of a unit: comment-free file hashes in include order plus the include edges.

    Each repository include is rewritten to a fixed token before hashing, so renaming or moving
    files and rewriting the include lines changes nothing, while changed content, a changed include
    order or another include graph does. __FILE__ and #line, which would make a path part of the
    code, are refused.
    """
    names = set(blobs)
    dirs = sorted({PurePosixPath(n).parent for n in names})
    canon, edges = {}, {}
    for name, blob in blobs.items():
        text = strip_comments(blob, name)
        if FORBIDDEN_V2.search(text):
            _refuse(name, '__FILE__ or #line makes the path part of the code')
        out, targets = [], []
        for line in text.split('\n'):
            m = v1.STRICT_INCLUDE.fullmatch(line)
            hit = _resolve(name, m.group(1) or m.group(2), '"' if m.group(1) else '<', names, dirs) if m else None
            if hit is None:
                out.append(line)
            else:
                out.append(REPO_INCLUDE)
                targets.append(hit)
        canon[name] = hashlib.sha256('\n'.join(out).encode()).hexdigest()
        edges[name] = targets
    included = {t for targets in edges.values() for t in targets}
    roots = sorted((n for n in names if n not in included), key=lambda n: canon[n])
    order, seen = [], set()

    def visit(name):
        if name in seen:
            return
        seen.add(name)
        order.append(name)
        for target in edges[name]:
            visit(target)

    for name in roots:
        visit(name)
    for name in sorted(names - seen, key=lambda n: canon[n]):  # include cycles with no outside includer
        visit(name)
    lines = [f'F {canon[n]}' for n in order]
    lines += sorted(f'E {canon[n]} {canon[t]} {i}' for n in names for i, t in enumerate(edges[n]))
    return hashlib.sha256(('\n'.join(lines) + '\n').encode()).hexdigest()


def unit_digest(blobs, method=None):
    """The digest of in-memory unit contents {path: bytes} under `method` (default: the current one)."""
    method = DIGEST_METHOD if method is None else method
    if not blobs:
        raise ValueError('translation unit has no files')
    for name in blobs:
        rel = PurePosixPath(name)
        if rel.is_absolute() or '..' in rel.parts:
            raise ValueError(f'translation unit path must be repository-relative: {name}')
    if method == 'tu-sha256-v1':
        return hashlib.sha256(''.join(f'{hashlib.sha256(blobs[n]).hexdigest()}  {PurePosixPath(n)}\n'
                                      for n in sorted(blobs)).encode()).hexdigest()
    if method == 'tu-sha256-v2':
        return _unit_digest_v2(dict(blobs))
    raise ValueError(f'unknown digest method {method!r}')


def tu_digest(root, paths, method=None):
    """The digest of the unit's files under `method` (default: the current one)."""
    method = DIGEST_METHOD if method is None else method
    if method == 'tu-sha256-v1':
        return v1.tu_digest(root, paths)
    for name in paths:
        rel = PurePosixPath(name)
        if rel.is_absolute() or '..' in rel.parts:
            raise ValueError(f'translation unit path must be repository-relative: {name}')
    return unit_digest({n: (Path(root) / n).read_bytes() for n in set(paths)}, method)


def run_digest_problem(source):
    """Why the record's run_digest fields are malformed, or None. Absent fields are valid."""
    has = [k for k in ('run_digest', 'run_digest_method') if k in source]
    if not has:
        return None
    if len(has) != 2:
        return 'run_digest and run_digest_method come together'
    if source['run_digest_method'] != 'tu-sha256-v1' or source.get('digest_method') == 'tu-sha256-v1':
        return 'run_digest is the v1 digest kept by a record whose own digest is newer'
    if not (isinstance(source['run_digest'], str) and re.fullmatch(r'[0-9a-f]{64}', source['run_digest'])):
        return 'run_digest is not a SHA-256'
    return None


def run_revision(source):
    """The source revision the record's comparator runs embed: the v1 digest kept at migration, else the record's own."""
    return source['run_digest'] if 'run_digest' in source else source.get('digest')


def review_binds(method, digest, source):
    """Whether a review of (method, digest) reviewed this record's source: the same digest under
    the same method, either the record's own or the one it kept at migration."""
    if method == source.get('digest_method') and digest == source.get('digest'):
        return True
    return 'run_digest' in source and method == source['run_digest_method'] and digest == source['run_digest']


if __name__ == '__main__':
    args = sys.argv[1:]
    method = None
    if args[:1] == ['--method'] and len(args) > 1:
        method, args = args[1], args[2:]
    if not args:
        raise SystemExit(__doc__)
    print(tu_digest(Path.cwd(), args, method))
