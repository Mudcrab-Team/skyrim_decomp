"""tools/usage_census.py on synthetic transcripts (no real transcript, no game data)."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import usage_census as uc  # noqa: E402


def assistant(mid, ts, usage, model='claude-sonnet-5-5', tools=()):
    content = [{'type': 'tool_use', 'id': 'tu%d' % i, 'name': name, 'input': inp} for i, (name, inp) in enumerate(tools)]
    return {'type': 'assistant', 'timestamp': ts, 'message': {'id': mid, 'model': model, 'usage': usage,
                                                              'content': content}}


def usage(inp=0, cw=0, cr=0, out=0, h1=None):
    u = {'input_tokens': inp, 'cache_creation_input_tokens': cw, 'cache_read_input_tokens': cr, 'output_tokens': out}
    if h1 is not None:
        u['cache_creation'] = {'ephemeral_1h_input_tokens': h1, 'ephemeral_5m_input_tokens': cw - h1}
    return u


class Transcript(unittest.TestCase):
    def write(self, rows):
        d = tempfile.mkdtemp()
        p = Path(d) / 'agent-a.jsonl'
        p.write_text(''.join(json.dumps(r) + '\n' for r in rows))
        return p

    def test_streamed_ids_once_and_attempts(self):
        rows = [
            assistant('m1', '2026-01-01T00:00:00Z', usage(10, 1000, 0, 5)),
            assistant('m1', '2026-01-01T00:00:01Z', usage(10, 1000, 0, 50)),   # same id, final counts
            assistant('m2', '2026-01-01T00:01:00Z', usage(1, 0, 1000, 20),
                      tools=[('Bash', {'command': 'tools/verifier/attempt .local/tasks/x'})]),
            assistant('m3', '2026-01-01T00:02:00Z', usage(1, 0, 2000, 30),
                      tools=[('Bash', {'command': 'tools/verifier/attempt .local/tasks/x'})]),
            {'type': 'assistant', 'timestamp': '2026-01-01T00:03:00Z',
             'message': {'id': 'x', 'model': '<synthetic>', 'usage': usage(0, 0, 0, 0), 'content': []}},
        ]
        s = uc.scan(self.write(rows))
        self.assertEqual(s['requests'], 3)
        k = s['models']['claude-sonnet-5-5']
        self.assertEqual((k['input'], k['cw5m'], k['cache_read'], k['output']), (12, 1000, 3000, 100))
        self.assertEqual(s['attempts'], 2)
        # Requests up to and including the one that issued the first attempt.
        self.assertEqual(s['before_first_attempt']['output'], 70)
        expected = (12 * 2.0 + 1000 * 2.5 + 3000 * 0.10 + 100 * 10.0) / 1e6
        self.assertAlmostEqual(s['usd']['claude-sonnet-5-5'], round(expected, 4))

    def test_reports_and_compaction(self):
        rows = [
            {'type': 'user', 'message': {'content': '<task-notification>' + 'x' * 81}},
            assistant('m1', '2026-01-01T00:00:00Z', usage(1, 0, 0, 1), model='claude-fable-5-2',
                      tools=[('Agent', {})]),
            {'type': 'user', 'message': {'content': [{'type': 'tool_result', 'tool_use_id': 'tu0',
                                                      'content': 'y' * 40}]}},
            assistant('m2', '2026-01-01T00:01:00Z', usage(1, 0, 0, 1), model='claude-fable-5-2'),
            {'type': 'system', 'subtype': 'compact_boundary'},
            assistant('m3', '2026-01-01T00:02:00Z', usage(1, 0, 0, 1), model='claude-fable-5-2'),
        ]
        s = uc.scan(self.write(rows))
        self.assertEqual(s['report_chars']['task_notification'], 100)
        self.assertEqual(s['report_chars']['result:agent'], 40)
        self.assertEqual(s['compactions'], 1)
        self.assertEqual(s['report_reread_chars'], 100 + 140 + 0)

    def test_window_filter(self):
        rows = [assistant('m1', '2026-01-01T00:00:00Z', usage(out=5)),
                assistant('m2', '2026-01-01T06:00:00Z', usage(out=7))]
        p = self.write(rows)
        w = (uc.parse_ts('2026-01-01T05:00:00Z'), uc.parse_ts('2026-01-01T07:00:00Z'))
        self.assertEqual(uc.scan(p, w)['models']['claude-sonnet-5-5']['output'], 7)


class Prices(unittest.TestCase):
    def test_cache_write_lifetimes(self):
        k = uc.usage_kinds(usage(0, 100, 0, 0, h1=60))
        self.assertEqual((k['cw1h'], k['cw5m']), (60, 40))
        k = uc.usage_kinds(usage(0, 100, 0, 0))
        self.assertEqual((k['cw1h'], k['cw5m']), (0, 100))

    def test_haiku_long_prompt_tier(self):
        short = uc.price('claude-haiku-5-5', {'input': 1000, 'cw5m': 0, 'cw1h': 0, 'cache_read': 0, 'output': 0})
        long_ = uc.price('claude-haiku-5-5', {'input': 1000, 'cw5m': 0, 'cw1h': 0, 'cache_read': 200000,
                                              'output': 0})
        self.assertAlmostEqual(short, 1000 * 0.10 / 1e6)
        self.assertAlmostEqual(long_, (1000 * 0.50 + 200000 * 0.05) / 1e6)

    def test_unknown_model_is_not_priced(self):
        self.assertIsNone(uc.price('some-model', uc.zero()))


class Roles(unittest.TestCase):
    def test_rules(self):
        self.assertEqual(uc.role_of('drafter', 'Draft batch5 X'), ('drafter', 'draft'))
        self.assertEqual(uc.role_of('reviewer', 'Review wave2 batch 1'), ('reviewer', 'function-review'))
        self.assertEqual(uc.role_of('reviewer', 'Review comparator 0.6'), ('reviewer', 'machinery-review'))
        self.assertEqual(uc.role_of('engineer', 'Accept wave 2'), ('engineer', 'integration'))
        self.assertEqual(uc.role_of('engineer', 'Near-miss round: x'), ('engineer', 'triage'))
        self.assertEqual(uc.role_of('engineer', 'Build source digests'), ('engineer', 'tooling'))


if __name__ == '__main__':
    unittest.main()
