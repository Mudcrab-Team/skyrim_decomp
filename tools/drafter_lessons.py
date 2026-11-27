#!/usr/bin/env python3
"""Rank whole lesson entries by a checked vocabulary of tags."""
import json
import re
from pathlib import Path
import lesson_tags

ENTRY = re.compile(r'(?=^<a id="(?:rule|lesson)-\d+"></a>)', re.M)


def entries(repo):
    repo = Path(repo)
    allowed = lesson_tags.vocabulary(repo)
    for rel in ('docs/matching-cookbook.md', 'docs/near-tier-lessons.md'):
        for part in ENTRY.split((repo / rel).read_text(encoding='utf-8'))[1:]:
            body = re.split(r'^## ', part, maxsplit=1, flags=re.M)[0].strip()
            anchor = re.search(r'id="([^"]+)"', body).group(1)
            yield rel + '#' + anchor, body, lesson_tags.parse(body, allowed)
    for path in sorted((repo / 'docs/cookbook-notes').glob('*.md')):
        if path.name != 'README.md':
            body = path.read_text(encoding='utf-8').strip()
            yield path.relative_to(repo).as_posix(), body, lesson_tags.parse(body, allowed)


def _json(path):
    try:
        return json.loads(Path(path).read_text())
    except (OSError, ValueError):
        return {}


def tags_for(repo, local, rva, fn=None, task_dir=None):
    """Derive tags from available metadata; missing data is not inferred as a fact."""
    import drafter_sheet
    repo, local = Path(repo), Path(local)
    pieces = []
    fn = fn or {}
    for key in ('name', 'family', 'shape', 'shape_class', 'wall', 'wall_class', 'callees', 'sibling'):
        if fn.get(key):
            pieces.append(str(fn[key]))
    tasks = [Path(task_dir)] if task_dir else drafter_sheet.task_for([local / 'tasks', local / 'contrib/tasks'], rva)
    if len(tasks) == 1:
        task = tasks[0]
        data = _json(task / 'task.json')
        for member in data.get('functions', []):
            if drafter_sheet.rva_value(member.get('rva', 0)) == rva:
                pieces.extend(str(member.get(k, '')) for k in ('community_name', 'family', 'shape', 'wall_class'))
                pack = Path(member.get('pack') or '')
                if member.get('pack'):
                    if not pack.is_absolute():
                        pack = repo / pack
                    readme = pack / 'README.md'
                    if readme.is_file():
                        from unit_skeleton import readme_section
                        pieces.append(readme_section(readme.read_text(), 'References leaving the function'))
        x64 = _json(task / 'sibling_x64.json')
        lead = (x64.get('functions') or {}).get(f'0x{rva:x}', {})
        for candidate in (lead.get('candidates') or [])[:3]:
            pieces.extend(str(candidate.get(k, '')) for k in ('game', 'name'))
        for filename in ('sibling.md', 'bind-hints.json', 'wall.json', 'hints.json'):
            path = task / filename
            if path.is_file():
                pieces.append(path.read_text(errors='replace')[:30000])
        attempts = sorted((task / 'attempts').glob('[0-9][0-9][0-9]'))
        if attempts:
            alignment = _json(attempts[-1] / f'0x{rva:x}' / 'align.json')
            for key in ('classes', 'suggestion'):
                if alignment.get(key):
                    pieces.append(str(alignment[key]))
            for filename in ('wall.json', 'summary.json'):
                path = attempts[-1] / filename
                if path.is_file():
                    pieces.append(path.read_text(errors='replace')[:30000])
    # Local lead files are optional indexes, never copied into the output.
    lead_paths = list((local / 'near-pilot').glob(f'*/leads/0x{rva:x}.md'))
    lead_paths += list((local / 'leads').glob(f'0x{rva:x}.md'))
    for lead_path in lead_paths:
        pieces.append('sibling ' + lead_path.read_text(errors='replace')[:30000])
    for path in (repo / 'data/hints.jsonl', local / 'analysis/hints.jsonl', local / 'hints.jsonl'):
        if not path.is_file():
            continue
        with path.open() as stream:
            for line in stream:
                try:
                    row = json.loads(line)
                    val = row.get('rva')
                    if val is not None and drafter_sheet.rva_value(val) == rva:
                        pieces.extend(str(row.get(k, '')) for k in ('family', 'shape', 'shape_class', 'wall', 'wall_class', 'callees', 'sibling', 'lead', 'tags'))
                except (ValueError, TypeError, AttributeError):
                    continue
    tags = lesson_tags.infer(' '.join(pieces))
    text = ' '.join(pieces).lower()
    tags.update(tag for tag in lesson_tags.vocabulary(repo) if tag in text)
    return tags


def select(repo, rva=None, tags=(), max_chars=12000):
    if max_chars < 200:
        raise ValueError('--max-chars must be at least 200')
    tags = set(tags)
    unknown = tags - lesson_tags.vocabulary(repo)
    if unknown:
        raise ValueError('unknown lesson tags: ' + ', '.join(sorted(unknown)))
    ranked = []
    exact = re.compile(r'(?<![0-9a-f])(?:0x)?0*' + format(rva, 'x') + r'(?![0-9a-f])', re.I) if rva is not None else None
    for source, body, entry_tags in entries(repo):
        if entry_tags is None:
            raise ValueError(f'{source}: missing or invalid tags')
        overlap = tags & entry_tags
        score = len(overlap) + (10 if exact and exact.search(source + ' ' + body) else 0)
        if score:
            ranked.append((-score, source, body))
    ranked.sort()
    title = f'0x{rva:x}' if rva is not None else 'selected tags'
    output = f'Lessons for {title}; tags: {", ".join(sorted(tags)) or "none known"} (leads, not evidence):\n'
    shown = 0
    for _, source, body in ranked:
        block = f'\n--- {source} ---\n{body}\n'
        if len(output) + len(block) <= max_chars:
            output += block
            shown += 1
    if not shown:
        output += 'No complete indexed match fits; consult the full cookbook and lessons as needed.\n'
    return output[:max_chars]
