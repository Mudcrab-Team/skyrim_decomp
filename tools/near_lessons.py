#!/usr/bin/env python3
"""Check and summarise docs/near-tier-lessons.md, the lessons from the near-tier drafting pilot.

    python3 tools/near_lessons.py                 check the file; exit 1 on a finding (codes only, never text)
    python3 tools/near_lessons.py --summary       counts by status, confidence and model, and the lessons per cookbook rule
    python3 tools/near_lessons.py --file PATH     another lessons file (tests)

A lesson is one block in the cookbook's shape:

    <a id="lesson-N"></a>
    **LN. Title.** (repeated|single|reported)
    Status: mapped|candidate|contradicted|contested|open. Found by: Sonnet, Sol, Opus. Rules: 5 agrees, 48 extends | none.
    Symptom: ...
    Fix: ...                                         (an open lesson may say `Tried:` instead)
    Evidence: 0x<rva> <move> (<model>[, <model>]); ...
    Still failing: 0x<rva>, ...                      (optional)

`<move>` is a signed number of sim points, `flat`, `callees` (callee agreement moved, sim did not) or `behaviour`
(a defect the score does not see). The check refuses a lesson with no evidence, a model it names that is not in
`Found by`, a rule number the cookbook does not have, a status that disagrees with its `Rules` line, a
`repeated` lesson whose evidence names only one function, and anything `tools/leakgrep.py` refuses.
"""
import argparse
import collections
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import leakgrep  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
LESSONS = Path('docs/near-tier-lessons.md')
COOKBOOK = Path('docs/matching-cookbook.md')
MODELS = ('Sonnet', 'Sol', 'Opus')
CONFIDENCE = ('repeated', 'single', 'reported')
STATUS = ('mapped', 'candidate', 'contradicted', 'contested', 'open')
VERBS = ('agrees', 'extends', 'qualifies', 'contradicts')
ENTRY = re.compile(r'(0x[0-9a-f]{3,8}) ([+-]\d+(?:\.\d+)?|flat|callees|behaviour) \(((?:Sonnet|Sol|Opus)(?:, (?:Sonnet|Sol|Opus))*)\)\Z')
HEAD = re.compile(r'\*\*L(\d+)\. (.+)\.\*\* \((\w+)\)\Z')
ANCHOR = re.compile(r'<a id="lesson-(\d+)"></a>\Z')
RULE_HEAD = re.compile(r'\*\*(\d+)\. ')
RVA = re.compile(r'0x[0-9a-f]{3,8}\Z')


def cookbook_rules(text):
    return {int(m.group(1)) for line in text.splitlines() if (m := RULE_HEAD.match(line))}


def parse(text):
    """[dict(id, title, confidence, fields, line)] for every lesson block, in file order."""
    lessons, current = [], None
    for number, line in enumerate(text.splitlines(), 1):
        anchor = ANCHOR.match(line)
        if anchor:
            current = dict(anchor=int(anchor.group(1)), line=number, id=None, title='', confidence='', fields={}, body='')
            lessons.append(current)
            continue
        if current is None:
            continue
        if line.startswith('## '):
            current = None
            continue
        head = HEAD.match(line)
        if head and current['id'] is None:
            current['id'], current['title'], current['confidence'] = int(head.group(1)), head.group(2), head.group(3)
            continue
        for key in ('Status', 'Evidence', 'Still failing'):
            if line.startswith(key + ':'):
                current['fields'][key] = line[len(key) + 1:].strip()
                current['last'] = None if key == 'Status' else key
                break
        else:
            if not line.strip():
                current['last'] = None
            elif current.get('last'):
                current['fields'][current['last']] += ' ' + line.strip()
            else:
                current['body'] = current.get('body', '') + ' ' + line.strip()
    return lessons


def status_line(value):
    """(status, found by, rules) from `mapped. Found by: Opus. Rules: 5 agrees, 48 extends.`."""
    status = value.split('.', 1)[0].strip()
    found = re.search(r'Found by: ([A-Za-z, ]+)\.', value)
    rules = re.search(r'Rules: (.+?)\.?\Z', value)
    models = [m.strip() for m in found.group(1).split(',')] if found else []
    pairs = []
    if rules and rules.group(1).strip() != 'none':
        for part in rules.group(1).split(','):
            bits = part.split()
            pairs.append((int(bits[0]) if bits and bits[0].isdigit() else None, bits[1] if len(bits) > 1 else ''))
    return status, models, (pairs if rules else None)


def check(text, rules):
    """Reason codes with line numbers for a lessons file, never the text: [(line, code)]."""
    out = []
    lessons = parse(text)
    if not lessons:
        out.append((1, 'no-lessons'))
    for expected, lesson in enumerate(lessons, 1):
        line, f = lesson['line'], lesson['fields']
        if lesson['id'] is None:
            out.append((line, 'no-title'))
            continue
        if lesson['anchor'] != lesson['id'] or lesson['id'] != expected:
            out.append((line, 'id-order'))
        if lesson['confidence'] not in CONFIDENCE:
            out.append((line, 'confidence'))
        for key in ('Status', 'Evidence'):
            if not f.get(key):
                out.append((line, f'missing-{key.lower()}'))
        if not re.search(r'\bSymptom( and fix)?:', lesson['body']):
            out.append((line, 'missing-symptom'))
        if not re.search(r'\bFix:|\bSymptom and fix:|\bTried:', lesson['body']):
            out.append((line, 'missing-fix'))
        if 'Status' not in f:
            continue
        status, found, pairs = status_line(f['Status'])
        if status not in STATUS:
            out.append((line, 'status'))
        if not found or any(m not in MODELS for m in found):
            out.append((line, 'found-by'))
        if pairs is None:
            out.append((line, 'rules-line'))
            pairs = []
        for number, verb in pairs:
            if number not in rules:
                out.append((line, 'unknown-rule'))
            if verb not in VERBS:
                out.append((line, 'rule-verb'))
        verbs = {verb for _n, verb in pairs}
        if status == 'mapped' and (not pairs or 'contradicts' in verbs):
            out.append((line, 'mapped-needs-rule'))
        if status == 'contradicted' and 'contradicts' not in verbs:
            out.append((line, 'contradicted-needs-verb'))
        if status == 'candidate' and pairs:
            out.append((line, 'candidate-has-rule'))
        if status != 'contradicted' and 'contradicts' in verbs:
            out.append((line, 'verb-needs-status'))
        entries = [e.strip().rstrip('.') for e in f.get('Evidence', '').split(';') if e.strip()]
        rvas = set()
        for entry in entries:
            m = ENTRY.match(entry)
            if not m:
                out.append((line, 'evidence-entry'))
                continue
            rvas.add(m.group(1))
            if any(model not in found for model in m.group(3).split(', ')):
                out.append((line, 'evidence-model'))
        if lesson['confidence'] == 'repeated' and len(rvas) < 2:
            out.append((line, 'repeated-needs-two-functions'))
        for rva in (r.strip() for r in f.get('Still failing', '').rstrip('.').split(',') if r.strip()):
            if not RVA.match(rva):
                out.append((line, 'still-failing'))
    for _name, n, code in leakgrep.scan_diff('+++ b/near.md\n@@ -0,0 +1 @@\n' + ''.join('+' + t + '\n' for t in text.splitlines())):
        out.append((n, 'leak-' + code))
    return out


def summary(lessons):
    by_status = collections.Counter()
    by_confidence = collections.Counter()
    by_model = collections.Counter()
    by_rule = collections.defaultdict(list)
    for lesson in lessons:
        f = lesson['fields']
        status, found, pairs = status_line(f.get('Status', ''))
        by_status[status] += 1
        by_confidence[lesson['confidence']] += 1
        for model in found:
            by_model[model] += 1
        for number, verb in pairs or []:
            by_rule[number].append((lesson['id'], verb))
    lines = [f'{len(lessons)} lessons',
             'status: ' + ', '.join(f'{k} {by_status[k]}' for k in STATUS),
             'confidence: ' + ', '.join(f'{k} {by_confidence[k]}' for k in CONFIDENCE),
             'found by: ' + ', '.join(f'{k} {by_model[k]}' for k in MODELS),
             'rules: ' + '; '.join(f'{n}: ' + ', '.join(f'L{i} {v}' for i, v in sorted(by_rule[n])) for n in sorted(by_rule))]
    return '\n'.join(lines)


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    p.add_argument('--file', type=Path, default=None)
    p.add_argument('--cookbook', type=Path, default=None)
    p.add_argument('--summary', action='store_true')
    a = p.parse_args(argv)
    path = a.file or ROOT / LESSONS
    text = path.read_text(encoding='utf-8')
    if a.summary:
        print(summary(parse(text)))
        return 0
    rules = cookbook_rules((a.cookbook or ROOT / COOKBOOK).read_text(encoding='utf-8'))
    findings = check(text, rules)
    for line, code in findings:
        print(f'{path.name}:{line}: {code}')
    if not findings:
        print(f'{len(parse(text))} lessons ok')
    return 1 if findings else 0


if __name__ == '__main__':
    sys.exit(main())
