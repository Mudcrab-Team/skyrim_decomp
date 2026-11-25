"""Diagnostic progress only. Comparator results and hard attempt budgets remain authoritative."""
import json
from pathlib import Path

STUCK_MINUTES = 5
PERMUTE_MIN_PERCENT = 90
PERMUTE_BUDGET_SECONDS = 300


def measure(report, alignment=None):
    if alignment and isinstance(alignment.get('matching_bytes'), int):
        return dict(metric='aligned_matching_bytes', value=alignment['matching_bytes'],
                    total=alignment['target_bytes'], regions=alignment['matching_regions'])
    coverage = report.get('coverage') or {}
    total = coverage.get('code_bytes_total')
    if isinstance(total, int):
        return dict(metric='compared_code_bytes', value=(coverage.get('code_bytes_exact') or 0)
                    + (coverage.get('code_bytes_by_reference') or 0), total=total)
    return None


def read_json(path):
    try:
        value = json.loads(Path(path).read_text())
        return value if isinstance(value, dict) else {}
    except (OSError, ValueError):
        return {}


def update(current, history, counted=True, now=None):
    """Compare with the previous measured attempt; reset patience only on a new best.

    History is already scoped to a task and tier. Missing diagnostics never become fake zeroes.
    Changing diagnostic methods starts a new baseline; oscillating below a best is no improvement.
    """
    out = {}
    for rva, metric in current.items():
        if metric is None:
            out[rva] = None
            continue
        prior = next((row['progress'][rva] for row in reversed(history)
                      if (row.get('progress') or {}).get(rva)), None)
        if prior and (prior['metric'], prior['total']) != (metric['metric'], metric['total']):
            prior = None
        value = metric['value']
        best = max(value, prior['best']) if prior else value
        improved = prior is not None and value > prior['best']
        out[rva] = dict(metric, previous=prior['value'] if prior else None,
                        delta=value - prior['value'] if prior else None, best=best,
                        no_improvement=(0 if prior is None or improved else
                                        prior['no_improvement'] + int(counted if isinstance(counted, bool) else rva in counted)))
        if now is not None:
            out[rva]['best_at'] = now if prior is None or improved else prior.get('best_at', now)
    return out


def stuck_advice(rva, metric, patience, now, *, permute_dirs=()):
    if not metric or metric['total'] <= 0 or not metric['no_improvement']:
        return None
    if metric['no_improvement'] >= patience:
        reason = f'{metric["no_improvement"]} counted attempts'
    elif now - metric.get('best_at', now) >= STUCK_MINUTES * 60:
        reason = f'{STUCK_MINUTES} minutes'
    else:
        return None
    if any((directory / name).is_file() for directory in permute_dirs
           for name in ('history.jsonl', 'run.log', 'result.json')):
        route = 'permuter exhausted; use wall-identifier to pick a structural change'
    elif 100 * metric['best'] >= PERMUTE_MIN_PERCENT * metric['total']:
        route = f'permute (one run, {PERMUTE_BUDGET_SECONDS}s search budget)'
    else:
        route = 'park in the near-miss pool'
    return f'stuck {rva}: no gain in {reason} → {route}'


def describe(rva, metric, patience):
    if metric is None:
        return f'progress {rva}: unavailable; fix diagnostics before judging improvement (hard cap still applies).'
    delta = f'{metric["delta"]:+d} vs previous' if metric['delta'] is not None else 'first measurement'
    regions = f'; {metric["regions"]} matching regions' if 'regions' in metric else ''
    return (f'progress {rva}: {metric["metric"]} {metric["value"]}/{metric["total"]} ({delta}); '
            f'best {metric["best"]}; no improvement {metric["no_improvement"]}/{patience}{regions}.')


def guidance(patience):
    return (f'Keep going while matching bytes rise, even if the first mismatch stays put; stop after '
            f'{patience} counted attempts or {STUCK_MINUTES} minutes without a new best, '
            'or at the hard attempt cap. '
            'Progress is diagnostic, never match evidence.')
