#!/usr/bin/env python3
"""Prepare private Wine comparator output with fresh toolchain checks for CI confirmation."""
import argparse
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import pipeline
import runners
import compare_batch


def run(directory):
    task = pipeline.load_task(directory)
    files, _ = pipeline.unit_manifest(task)
    host = runners.for_attempt()
    kept = compare_batch.confirm_done(task['dir'], task, files, host and host.get('host_id'))
    if kept is not None:
        return kept  # an earlier run (batched or before a restart) already confirmed these exact sources
    if not host or not ((host.get('backend'), host.get('loader'), host.get('host_id')) ==
                        ('local', 'wine', 'mac-wine') or
                        (host.get('backend'), host.get('loader')) == ('ssh', 'native')):
        raise runners.RunnerError('CI first-host preparation requires a configured Wine or native SSH host')
    worker = runners.AgentHost(host, task, log=print, fresh_prep=True)
    code, _ = worker.run(files, task['dir'] / '.confirm-stage' / host['host_id'])
    worker.fetch(task['dir'] / 'confirm' / host['host_id'])
    compare_batch.mark_confirm(task['dir'], task, files, host['host_id'], code)
    return code


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('task', type=Path)
    args = parser.parse_args()
    try:
        return run(args.task)
    except Exception:
        print('ERROR: Wine preparation infrastructure failed; see private runner diagnostics.')
        return 2


if __name__ == '__main__':
    raise SystemExit(main())
