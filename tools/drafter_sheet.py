#!/usr/bin/env python3
"""Compact task facts, without including listings or decompiler output."""
import json
from pathlib import Path
import unit_skeleton


def rva_value(value):
    return value if isinstance(value, int) else int(value, 16)


def task_for(roots, rva):
    found = []
    for root in roots:
        for path in Path(root).glob('**/task.json'):
            try:
                task = json.loads(path.read_text())
                if any(rva_value(f['rva']) == rva for f in task.get('functions', [])):
                    found.append(path.parent)
            except (OSError, ValueError, KeyError, TypeError):
                continue
    return sorted(set(found))


def render(repo, task_dir, rva, max_chars=8000):
    task_dir = Path(task_dir)
    task = json.loads((task_dir / 'task.json').read_text())
    matches = [f for f in task.get('functions', []) if rva_value(f['rva']) == rva]
    if not matches:
        raise ValueError(f'0x{rva:x} is not in {task_dir}/task.json')
    fn = matches[0]
    lines = [f'0x{rva:x}: {fn.get("community_name", "unknown name")} ({fn.get("size", "unknown")} bytes)',
             f'Build: {task.get("build_id", "unknown")}; unit: {task.get("compiled", "unknown")}; recipe: {task.get("recipe", "unknown")}',
             f'Task: {task_dir}; compared symbol: {fn.get("symbol", "unbound")}',
             f'Attempt: tools/verifier/attempt {task_dir}',
             f'Bind hints: {task_dir / "bind-hints.json"} (use only references in the pack).']
    pack = Path(fn['pack']) if fn.get('pack') else None
    if pack and not pack.is_absolute():
        pack = Path(repo) / pack
    if pack:
        readme = pack / 'README.md'
        if readme.is_file():
            text = readme.read_text()
            for section in ('Calling and return convention', 'References leaving the function'):
                part = unit_skeleton.readme_section(text, section)
                if part:
                    lines.extend([f'{section}:', part])
        lines.append(f'Private pack: {pack}; read locally only.')
    sibling = task_dir / 'sibling.md'
    if sibling.is_file():
        lines.extend(['Sibling leads (not match evidence):', sibling.read_text().strip()])
    x64 = task_dir / 'sibling_x64.json'
    if x64.is_file():
        record = json.loads(x64.read_text())
        leads = (record.get('functions') or {}).get(f'0x{rva:x}', {})
        candidates = leads.get('candidates') or []
        if candidates:
            lead = candidates[0]
            lines.append('Sibling x64 lead: ' + ' '.join(str(lead.get(k, '')) for k in
                         ('game', 'name', 'file', 'line', 'score')) +
                         (' exact_shape' if lead.get('exact_shape') else ''))
        lines.append(f'Further sibling x64 leads: {x64}; inspect exact_shape first.')
    lines.append('Layouts: ./sr facts 0x%x; python3 tools/header_index.py --class <Class>' % rva)
    text = '\n'.join(lines) + '\n'
    if len(text) > max_chars:
        suffix = f'\n[Sheet truncated; details remain in {task_dir} and the pack.]\n'
        text = text[:max_chars - len(suffix)].rsplit('\n', 1)[0] + suffix
    return text
