"""Short recovery advice at command boundaries; never changes a gate or a result."""
import argparse


def next_action(message, command=None):
    text = str(message).lower()
    if any(s in text for s in ('disk space', 'disk floor', 'low disk', 'no space left')):
        return ('Free disk space, then retry. '
                'Keep machine-specific paths in private configuration, out of tracked output.')
    if any(s in text for s in ('stale header', 'origin changed carried', 'stale-sibling', 'translation unit changed')):
        return ('Rebase and reconcile the header, re-confirm affected units using confirmation-pinned maps, '
                'then retry; keep report/source and symbol_map.path bindings together.')
    if any(s in text for s in ('symbol map', 'symbol-map', 'symbol_map', 'match record', 'report', 'symbols',
                               'record_refresh', 'source digest', 'source.digest', 'source: digest', 'translation unit digest')):
        return ('Use the confirmation-pinned map and history (record symbol_map.path), not a newer global map; '
                'set task.symbols and supply inventory report, source.translation_unit and request record_refresh for companion reports.')
    if 'review' in text or 'approval' in text or 'escalation' in text:
        return 'Obtain the required fresh Reviewer approval or resolve its blocker, then retry.'
    if any(s in text for s in ('model', '--agent', 'agent is required', 'worker', 'drafted-by')):
        return 'Name the actual model with --model (or --agent); project claims may use their profile default.'
    if 'compile' in text or 'include' in text:
        return 'Fix the named source/include or compiler error, then retry the same unit; retain prior passes.'
    if 'claim' in text or command == 'claims':
        return 'Refresh claims when online, choose unclaimed scope, then retry; retain existing local work.'
    if command == 'attempt':
        return 'Fix the named source/input issue; send task/config or runner preparation faults to the Engineer, then retry this unit.'
    if command == 'contrib':
        return 'Run contrib.py doctor, correct the named input, then retry the same command.'
    return 'Correct the named input, then retry.'


def explain(message, command=None):
    message = str(message)
    return message if '\nNext: ' in message else message + '\nNext: ' + next_action(message, command)


class ArgumentParser(argparse.ArgumentParser):
    def error(self, message):
        super().error(message + f'\nNext: run {self.prog} --help and correct the named argument.')
