#!/usr/bin/env python3
"""Summarize Claude Code JSONL transcripts without copying their contents.

Pass transcript files and/or directories; directories are searched recursively for JSONL.
Token usage is counted once per assistant message ID, not once per streamed content block.
Context is input + cache creation + cache reads, per assistant API response.
Tool results are attributed to the matching tool-use ID within each transcript.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import shlex

TOKEN_KEYS = ('input_tokens', 'cache_creation_input_tokens', 'cache_read_input_tokens', 'output_tokens')


def paths(inputs):
    found = set()
    for name in inputs:
        path = Path(name)
        if path.is_dir():
            found.update(p.resolve() for p in path.rglob('*.jsonl'))
        elif path.is_file():
            found.add(path.resolve())
        else:
            raise FileNotFoundError(name)
    return sorted(found)


def result_text(content):
    if isinstance(content, str):
        return content
    if isinstance(content, list):
        return ''.join(block.get('text', '') for block in content if isinstance(block, dict))
    return ''


def command_and_file(name, inputs):
    command = inputs.get('command', '') if isinstance(inputs, dict) else ''
    file = ''
    if isinstance(inputs, dict):
        file = inputs.get('file_path') or inputs.get('path') or ''
    if command:
        try:
            lexer = shlex.shlex(command, posix=True, punctuation_chars=';&|')
            lexer.whitespace_split = True
            lexer.commenters = ''
            words = list(lexer)
        except ValueError:
            words = command.split()
        # Shell invocations often begin with `cd ... &&`; classify the next command.
        while words and words[0] == 'cd' and any(w in ('&&', ';') for w in words):
            cut = next(i for i, w in enumerate(words) if w in ('&&', ';'))
            words = words[cut + 1:]
        executable = Path(words[0]).name if words else '(empty)'
        # For shell chains, the result is attributed to the first substantive command.
        # It cannot be split accurately among multiple commands.
        # Report the command name rather than shell text, which can contain private material.
        command = executable
        if not file and executable in ('cat', 'head', 'tail', 'sed', 'grep', 'rg'):
            candidates = [w for w in words[1:] if not w.startswith('-') and ('/' in w or '.' in w)]
            if candidates:
                file = candidates[-1]
    return command, file


def report(files):
    tokens, tools, commands, filesizes = Counter(), Counter(), Counter(), Counter()
    contexts = []
    for path in files:
        messages, uses, results = {}, {}, []
        with path.open(encoding='utf-8') as stream:
            for number, line in enumerate(stream, 1):
                try:
                    row = json.loads(line)
                except json.JSONDecodeError as exc:
                    raise ValueError(f'{path}:{number}: invalid JSON') from exc
                message = row.get('message') or {}
                if row.get('type') == 'assistant':
                    usage = message.get('usage')
                    if usage and message.get('id'):
                        messages[message['id']] = usage
                content = message.get('content')
                if not isinstance(content, list):
                    continue
                for block in content:
                    if not isinstance(block, dict):
                        continue
                    if row.get('type') == 'assistant' and block.get('type') == 'tool_use':
                        uses[block.get('id')] = (block.get('name', '(unknown)'), block.get('input') or {})
                    elif row.get('type') == 'user' and block.get('type') == 'tool_result':
                        results.append((block.get('tool_use_id'), len(result_text(block.get('content')))))
        for usage in messages.values():
            for key in TOKEN_KEYS:
                tokens[key] += usage.get(key, 0) or 0
            contexts.append(sum(usage.get(k, 0) or 0 for k in TOKEN_KEYS[:3]))
        for ident, size in results:
            name, inputs = uses.get(ident, ('(unknown)', {}))
            tools[name] += size
            command, file = command_and_file(name, inputs)
            if command:
                commands[command] += size
            if file:
                filesizes[file] += size
    return {'transcripts': len(files), 'turns': len(contexts), 'tokens': dict(tokens),
            'context_average': sum(contexts) / len(contexts) if contexts else 0,
            'context_max': max(contexts, default=0), 'tool_chars': dict(tools.most_common()),
            'command_chars': dict(commands.most_common()), 'file_chars': dict(filesizes.most_common())}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('paths', nargs='+', help='JSONL files or directories (recursive)')
    parser.add_argument('--json', action='store_true', help='emit machine-readable summary')
    args = parser.parse_args(argv)
    try:
        data = report(paths(args.paths))
    except (OSError, ValueError) as exc:
        parser.error(str(exc))
    if args.json:
        print(json.dumps(data, indent=2))
        return
    print(f"Transcripts: {data['transcripts']}; turns: {data['turns']}")
    for key, count in data['tokens'].items():
        print(f'{key}: {count:,}')
    print(f"Context per turn: average {data['context_average']:,.0f}; max {data['context_max']:,}")
    for key, title in [('tool_chars', 'Tool'), ('command_chars', 'Command'), ('file_chars', 'File')]:
        print(f'{title} result characters:')
        for name, count in data[key].items():
            print(f'  {name}: {count:,}')


if __name__ == '__main__':
    main()
