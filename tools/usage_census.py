"""Model usage and money per role from agent transcripts, for the token census.

    python3 tools/usage_census.py roles --session <session .jsonl> [--subagents DIR] [--out FILE]
    python3 tools/usage_census.py windows --root ~/.claude/projects --window START,END [...]

Reads only metadata from transcripts: message ids, model names, usage counters, timestamps,
tool names, tool-result lengths and whether a Bash call ran the draft loop's `attempt` command.
It never prints prompt, tool or response text. Output is counts, money and lengths.

Roles come from each subagent's `.meta.json` (agent type and short description) through the
ordered rules in ROLE_RULES; the top-level transcript is the orchestrator.

Prices are public list prices per million tokens, with the page and the date they were read in
PRICE_SOURCES. A model missing from PRICES is priced as None, never guessed.
"""
import argparse
from collections import Counter, defaultdict
import datetime as dt
import glob
import json
import os
from pathlib import Path
import re
import sys

PRICE_SOURCES = {
    'anthropic': ('https://platform.claude.com/docs/en/about-claude/pricing', '2026-11-12'),
    'openai': ('https://developers.openai.com/api/docs/pricing', '2026-11-12'),
}
# USD per million tokens: fresh input, 5-minute cache write, 1-hour cache write, cache read, output.
PRICES = {
    'claude-fable-5-2': {'input': 8.0, 'cw5m': 10.0, 'cw1h': 16.0, 'cache_read': 0.20, 'output': 40.0},
    'claude-opus-5-5': {'input': 4.0, 'cw5m': 5.0, 'cw1h': 8.0, 'cache_read': 0.20, 'output': 20.0},
    'claude-sonnet-5-5': {'input': 2.0, 'cw5m': 2.5, 'cw1h': 4.0, 'cache_read': 0.10, 'output': 10.0},
    'claude-opus-5': {'input': 5.0, 'cw5m': 6.25, 'cw1h': 10.0, 'cache_read': 0.50, 'output': 25.0},
    'claude-sonnet-5': {'input': 2.0, 'cw5m': 2.5, 'cw1h': 4.0, 'cache_read': 0.20, 'output': 10.0},
    # Haiku 5.5 has two tiers by prompt size (input + cache tokens of one request).
    'claude-haiku-5-5': {'input': 0.10, 'cw5m': 0.125, 'cw1h': 0.20, 'cache_read': 0.01, 'output': 0.50,
                         'long_over': 100_000,
                         'long': {'input': 0.50, 'cw5m': 0.625, 'cw1h': 1.0, 'cache_read': 0.05, 'output': 2.50}},
    # OpenAI bills no separate cache write; a cache write is fresh input there.
    'gpt-6-luna': {'input': 0.10, 'cw5m': 0.10, 'cw1h': 0.10, 'cache_read': 0.01, 'output': 0.50},
    'gpt-5.6-luna': {'input': 0.20, 'cw5m': 0.20, 'cw1h': 0.20, 'cache_read': 0.02, 'output': 1.20},
}
KINDS = ('input', 'cw5m', 'cw1h', 'cache_read', 'output')

# (role, stage) by agent type and description, first match wins. Function review is review of
# reconstructed functions; machinery review is review of tools, gates and policy.
ROLE_RULES = (
    (r'^(Draft |Haiku drafts|Sonnet control)', 'drafter', 'draft'),
    (r'^(Batch review|Review batch|Review wave|Sampling second|Review BSLSMB|Re-review packet|'
     r'Re-review relabelled|Delta review|Review first|Re-review first|Third review|Review post-review)',
     'reviewer', 'function-review'),
    (r'^(Review |Re-review )', 'reviewer', 'machinery-review'),
    (r'^(Accept |Integrate wave|Merge batch|Second-host|Update progress|Integrate Phase)', 'engineer', 'integration'),
    (r'^(Near-miss|Triage|Flag-test|Fix rejected|Diagnose|Merge triage|Fix deleting|Fix review-block)',
     'engineer', 'triage'),
    (r'^(Prepare|Select candidates|Pre-wave|Prep cheap)', 'engineer', 'prep'),
    (r'.', 'engineer', 'tooling'),
)
ATTEMPT = re.compile(r'tools/verifier/attempt\b')


def role_of(agent_type, description):
    for pattern, role, stage in ROLE_RULES:
        if re.search(pattern, description or ''):
            if role == 'reviewer' and agent_type not in ('reviewer', 'general-purpose'):
                continue
            return role, stage
    return 'engineer', 'tooling'


def zero():
    return dict.fromkeys(KINDS, 0)


def usage_kinds(u):
    """Our five kinds from one API usage record; cache writes split by lifetime when given."""
    cc = u.get('cache_creation') or {}
    total_cw = u.get('cache_creation_input_tokens') or 0
    h1 = cc.get('ephemeral_1h_input_tokens')
    m5 = cc.get('ephemeral_5m_input_tokens')
    if h1 is None and m5 is None:
        h1, m5 = 0, total_cw
    return {'input': u.get('input_tokens') or 0, 'cw5m': m5 or 0, 'cw1h': h1 or 0,
            'cache_read': u.get('cache_read_input_tokens') or 0, 'output': u.get('output_tokens') or 0}


def price(model, k):
    """USD of one request's kinds, or None when the model has no confirmed price."""
    p = PRICES.get(model)
    if p is None:
        return None
    if 'long_over' in p and k['input'] + k['cw5m'] + k['cw1h'] + k['cache_read'] > p['long_over']:
        p = p['long']
    return sum(k[x] * p[x] for x in KINDS) / 1e6


def parse_ts(s):
    return dt.datetime.fromisoformat(s.replace('Z', '+00:00')) if s else None


def scan(path, window=None):
    """Usage facts of one transcript. Streaming repeats a message id; the last record of an id wins.

    Returns {'models': {model: kinds}, 'usd': {model: usd or None}, 'requests', 'tools': Counter,
    'attempts', 'before_first_attempt': kinds summed over requests up to the first attempt call,
    'first', 'last', 'report_chars': {...}} where report_chars counts the lengths of what agents
    and tools returned into this context (task notifications, Agent results, other tool results).
    """
    by_id = {}
    order = []
    tool_names = {}
    tools = Counter()
    attempts = 0
    first_attempt_at = None
    chars = Counter()
    report_ctx = 0          # report characters in the live context since the last compaction
    ctx_at = {}
    compactions = 0
    first = last = None
    with open(path, encoding='utf-8', errors='replace') as f:
        for line in f:
            try:
                r = json.loads(line)
            except ValueError:
                continue
            t = r.get('type')
            ts = r.get('timestamp')
            m = r.get('message') if isinstance(r.get('message'), dict) else None
            if t == 'assistant' and m and m.get('usage') and m.get('model') not in (None, '<synthetic>'):
                when = parse_ts(ts)
                if window and not (when and window[0] <= when < window[1]):
                    continue
                mid = m.get('id') or ('line%d' % len(order))
                if mid not in by_id:
                    order.append(mid)
                    ctx_at[mid] = report_ctx
                by_id[mid] = (m.get('model'), usage_kinds(m['usage']), when)
                first = first or when
                last = when or last
                for c in m.get('content') or []:
                    if isinstance(c, dict) and c.get('type') == 'tool_use':
                        tools[c.get('name')] += 1
                        tool_names[c.get('id')] = c.get('name')
                        cmd = (c.get('input') or {}).get('command') if c.get('name') == 'Bash' else None
                        if isinstance(cmd, str) and ATTEMPT.search(cmd):
                            attempts += 1
                            if first_attempt_at is None:
                                first_attempt_at = len(order)
            elif t == 'user' and m:
                cont = m.get('content')
                if isinstance(cont, str):
                    key = 'task_notification' if cont.lstrip().startswith('<task-notification>') else 'user_text'
                    chars[key] += len(cont)
                    if key == 'task_notification':
                        report_ctx += len(cont)
                elif isinstance(cont, list):
                    for c in cont:
                        if isinstance(c, dict) and c.get('type') == 'tool_result':
                            body = c.get('content')
                            n = len(body) if isinstance(body, str) else sum(
                                len(x.get('text', '')) for x in body or [] if isinstance(x, dict))
                            name = tool_names.get(c.get('tool_use_id'), 'other')
                            kind = 'agent' if name in ('Agent', 'Task', 'SendMessage') else 'tool'
                            chars['result:' + kind] += n
                            if kind == 'agent':
                                report_ctx += n
            elif t == 'system' and r.get('subtype') == 'compact_boundary':
                compactions += 1
                report_ctx = 0
    models = defaultdict(zero)
    usd = defaultdict(float)
    unpriced = set()
    before = zero()
    for i, mid in enumerate(order):
        model, k, _ = by_id[mid]
        for x in KINDS:
            models[model][x] += k[x]
        p = price(model, k)
        if p is None:
            unpriced.add(model)
        else:
            usd[model] += p
        if first_attempt_at is not None and i < first_attempt_at:
            for x in KINDS:
                before[x] += k[x]
    return {'models': dict(models), 'usd': {m: (None if m in unpriced else round(v, 4)) for m, v in usd.items()},
            'requests': len(order), 'tools': tools, 'attempts': attempts,
            'before_first_attempt': before if first_attempt_at is not None else None,
            'first': first, 'last': last, 'report_chars': dict(chars), 'compactions': compactions,
            'report_reread_chars': sum(ctx_at.values())}


def add(a, b):
    for x in KINDS:
        a[x] = a.get(x, 0) + b.get(x, 0)
    return a


def cmd_roles(args):
    out = {'session': {}, 'agents': [], 'by_stage': {}, 'by_stage_model': {}}
    s = scan(args.session)
    out['session'] = {'role': 'orchestrator', 'stage': 'orchestration', 'models': s['models'], 'usd': s['usd'],
                      'requests': s['requests'], 'report_chars': s['report_chars'], 'tools': dict(s['tools']),
                      'compactions': s['compactions'], 'report_reread_chars': s['report_reread_chars']}
    stage_tot = defaultdict(lambda: {'agents': 0, 'tokens': zero(), 'usd': 0.0})
    stage_model = defaultdict(lambda: {'agents': 0, 'tokens': zero(), 'usd': 0.0})
    for m, k in s['models'].items():
        add(stage_tot['orchestration']['tokens'], k)
        stage_tot['orchestration']['usd'] += s['usd'].get(m) or 0
        add(stage_model['orchestration|' + m]['tokens'], k)
        stage_model['orchestration|' + m]['usd'] += s['usd'].get(m) or 0
    stage_tot['orchestration']['agents'] = 1
    sub = Path(args.subagents) if args.subagents else Path(args.session).with_suffix('') / 'subagents'
    for path in sorted(sub.glob('*.jsonl')):
        meta_path = path.with_suffix('.meta.json')
        meta = json.loads(meta_path.read_text()) if meta_path.exists() else {}
        role, stage = role_of(meta.get('agentType'), meta.get('description'))
        r = scan(path)
        label = (meta.get('description') or '').split()
        batch = next((w for w in label if re.match(r'(batch\d|second-batch|wave\d)', w)), None)
        row = {'agent': path.stem, 'agent_type': meta.get('agentType'), 'role': role, 'stage': stage,
               'batch': batch, 'models': r['models'], 'usd': r['usd'], 'requests': r['requests'],
               'attempts': r['attempts'], 'before_first_attempt': r['before_first_attempt'],
               'tool_calls': sum(r['tools'].values()),
               'wall_s': int((r['last'] - r['first']).total_seconds()) if r['first'] and r['last'] else 0}
        out['agents'].append(row)
        stage_tot[stage]['agents'] += 1
        for m, k in r['models'].items():
            add(stage_tot[stage]['tokens'], k)
            stage_tot[stage]['usd'] += r['usd'].get(m) or 0
            sm = stage_model[stage + '|' + m]
            sm['agents'] += 1
            add(sm['tokens'], k)
            sm['usd'] += r['usd'].get(m) or 0
    out['by_stage'] = {k: dict(v, usd=round(v['usd'], 2)) for k, v in sorted(stage_tot.items())}
    out['by_stage_model'] = {k: dict(v, usd=round(v['usd'], 2)) for k, v in sorted(stage_model.items())}
    text = json.dumps(out, indent=1, default=str)
    if args.out:
        Path(args.out).write_text(text + '\n')
    for k, v in out['by_stage'].items():
        print('%-18s agents %3d usd %9.2f %s' % (k, v['agents'], v['usd'], v['tokens']))
    return 0


def cmd_windows(args):
    """Usage of every transcript under --root inside each window, per model, with its API value."""
    roots = [os.path.expanduser(r) for r in args.root]
    files = []
    for r in roots:
        files += glob.glob(os.path.join(r, '**', '*.jsonl'), recursive=True)
    result = []
    for w in args.window:
        a, b = (parse_ts(x) for x in w.split(','))
        models = defaultdict(zero)
        usd = defaultdict(float)
        nfiles = 0
        for f in files:
            if os.path.getmtime(f) < a.timestamp():
                continue
            s = scan(f, (a, b))
            if s['requests']:
                nfiles += 1
            for m, k in s['models'].items():
                add(models[m], k)
                usd[m] += s['usd'].get(m) or 0
        result.append({'window': w, 'hours': round((b - a).total_seconds() / 3600, 2), 'transcripts': nfiles,
                       'models': dict(models), 'usd': {m: round(v, 2) for m, v in usd.items()},
                       'usd_total': round(sum(usd.values()), 2)})
    text = json.dumps(result, indent=1)
    if args.out:
        Path(args.out).write_text(text + '\n')
    print(text)
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    r = sub.add_parser('roles')
    r.add_argument('--session', required=True)
    r.add_argument('--subagents')
    r.add_argument('--out')
    w = sub.add_parser('windows')
    w.add_argument('--root', action='append', required=True)
    w.add_argument('--window', action='append', required=True, help='START,END in ISO 8601 UTC')
    w.add_argument('--out')
    args = ap.parse_args(argv)
    return {'roles': cmd_roles, 'windows': cmd_windows}[args.cmd](args)


if __name__ == '__main__':
    sys.exit(main())
