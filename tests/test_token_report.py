import json
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import token_report


class TokenReportTests(unittest.TestCase):
    def test_shell_prefix_is_skipped(self):
        command, path = token_report.command_and_file('Bash', {'command': 'cd repo; cat docs/example.md | head'})
        self.assertEqual(command, 'cat')
        self.assertEqual(path, 'docs/example.md')

    def test_streamed_messages_and_tool_results(self):
        use = {'type': 'tool_use', 'id': 'tool1', 'name': 'Bash', 'input': {'command': 'cat docs/example.md'}}
        usage = {'input_tokens': 3, 'cache_creation_input_tokens': 4, 'cache_read_input_tokens': 20, 'output_tokens': 5}
        rows = [
            {'type': 'assistant', 'message': {'id': 'msg1', 'usage': usage, 'content': [use]}},
            {'type': 'assistant', 'message': {'id': 'msg1', 'usage': usage, 'content': [{'type': 'text', 'text': 'ok'}]}},
            {'type': 'user', 'message': {'content': [{'type': 'tool_result', 'tool_use_id': 'tool1', 'content': 'hello'}]}},
        ]
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            transcript = root / 'a.jsonl'
            transcript.write_text(''.join(json.dumps(row) + '\n' for row in rows))
            result = token_report.report(token_report.paths([str(transcript), str(root)]))
        self.assertEqual(result['turns'], 1)
        self.assertEqual(result['tokens']['output_tokens'], 5)
        self.assertEqual(result['context_average'], 27)
        self.assertEqual(result['context_max'], 27)
        self.assertEqual(result['tool_chars'], {'Bash': 5})
        self.assertEqual(result['command_chars'], {'cat': 5})
        self.assertEqual(result['file_chars'], {'docs/example.md': 5})


if __name__ == '__main__':
    unittest.main()
