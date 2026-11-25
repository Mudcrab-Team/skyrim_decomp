"""Repair a stand-in twin whose body hands `this` to a parameter of the real owner class.

A stand-in owner is a copy of the exemplar's real class, so a call that takes the real class (a
pointer or a reference) rejects the copy. Passing `this` as a pointer of the real class compiles to
the same code, because the stand-in has the real class's layout and no base adjustment is involved.
The edit is driven by the compiler's own diagnostic, so only a call it rejected is touched.
"""
from pathlib import Path
import re

CONVERT = re.compile(
    r"(?P<path>reconstruction/\S+?)\((?P<line>\d+)\): error C2664: .*?cannot convert argument (?P<index>\d+) "
    r"from 'Owner[0-9a-f]+(?P<from> \*)?' to '(?P<target>[A-Za-z_][\w:]*)(?P<to> \*| &)'")
POINTER = re.compile(r'(?<![\w*&])this\b')
REFERENCE = re.compile(r'\*this\b')


def conversions(output):
    """[(path, line, index, target, kind)] for each rejected argument; kind is 'pointer' or 'reference'."""
    found = []
    for m in CONVERT.finditer(output):
        kind = 'pointer' if m['to'] == ' *' and m['from'] else 'reference' if m['to'] == ' &' and not m['from'] else None
        if kind:
            found.append((m['path'], int(m['line']), int(m['index']), m['target'], kind))
    return found


def argument_index(text, start):
    """1-based position of the call argument that contains offset `start` of `text`, or None."""
    depth, left = 0, None
    for i in range(start - 1, -1, -1):
        if text[i] in ')]}':
            depth += 1
        elif text[i] in '([{':
            if depth == 0:
                left = i
                break
            depth -= 1
    if left is None or text[left] != '(':
        return None
    index, depth = 1, 0
    for i in range(left + 1, start):
        if text[i] in '([{':
            depth += 1
        elif text[i] in ')]}':
            depth -= 1
        elif text[i] == ',' and depth == 0:
            index += 1
    return index


def patch(text, line, index, target, kind):
    """The text with the `this` argument number `index` of `line` read as the real class, or None."""
    lines = text.split('\n')
    if not 1 <= line <= len(lines):
        return None
    pattern = POINTER if kind == 'pointer' else REFERENCE
    hits = list(pattern.finditer(lines[line - 1]))
    if len(hits) != 1 or argument_index(lines[line - 1], hits[0].start()) != index:
        return None
    if lines[line - 1][:hits[0].start()].rstrip('*').endswith('>('):
        return None
    cast = f'reinterpret_cast<{target}*>(this)'
    lines[line - 1] = pattern.sub(cast if kind == 'pointer' else '*' + cast, lines[line - 1], count=1)
    return '\n'.join(lines)


def repair(files, output):
    """Apply every diagnosed conversion to the unit texts in `files` ({path below reconstruction/: text})."""
    changed = 0
    for path, line, index, target, kind in conversions(output):
        rel = path.removeprefix('reconstruction/')
        if rel in files and (text := patch(files[rel], line, index, target, kind)):
            files[rel] = text
            changed += 1
    return changed


def latest_log(task_dir):
    """The compiler's own output of the newest attempt; the attempt summary shortens long diagnostics."""
    attempts = sorted(Path(task_dir).glob('attempts/[0-9][0-9][0-9]'))
    log = attempts[-1] / 'compile.log' if attempts else None
    return log.read_text(encoding='utf-8', errors='replace') if log and log.is_file() else ''
