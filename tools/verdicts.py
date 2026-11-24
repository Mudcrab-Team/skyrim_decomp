#!/usr/bin/env python3
"""The verdicts the PR bot names per function, with each one's strike effect and next step.

The bot's internal verdict codes (`matched`, `debt`, `fail:host1`, `fail:host2`, `fail:review`, `fail:precheck`,
`fail:missing`, `fail:record`, `blocked`) say which stage stopped a function. This module names the
outcome for the contributor and keeps one table of what it means: the sticky comment shows a row per
function that was not accepted, and docs/contributor-card.md ("Verdicts") shows the same table
(tests/test_verdicts.py keeps the two equal).

A strike is recorded only by a maintainer, from a trusted CI hash report, for an explicit claim the
completed comparison contradicts (tools/contributor_standing.py). A verdict's strike column says
whether the failure is the kind that can count; it never records anything by itself.
"""
import re

# kind -> (meaning, strike, next step); the order is the order of the documentation table.
KINDS = {
    'matched': (
        'Byte match on both hosts and one approved review.',
        'none',
        'Merged and recorded; nothing to do.'),
    'mismatch': (
        'The compiled function differs from the game\'s bytes on a host that finished the comparison.',
        'counts when an explicit claim is contradicted by the completed CI hash comparison',
        'Run `./sr compare`, read the first mismatch and the hint, change the source and push.'),
    'compile_error': (
        'Nothing was compared: the unit did not compile, an include did not resolve, or no symbol bound to the RVA.',
        'contributor\'s fault, no ledger entry today (the strike ledger excludes compile and setup errors)',
        'Compile it locally with the unit\'s recipe (`./sr compare`), fix the error, include or binding and push.'),
    'unfit': (
        'Both hosts byte-matched the function on its own, but not as part of its unit file or the others in the PR: '
        'a mechanical check on the unit (lint, undeclared adapted body, or a binding that does not equal the unit as '
        'pushed) refused it before any review.',
        'none',
        'Keep the function in a unit of its own or fix the finding the comment names; merge main if the branch '
        'is behind. Left alone, it goes back to the pool unclaimed.'),
    'needs_review': (
        'A failure on our side: toolchain, verifier host, CI hash infrastructure, or a record that could not be '
        'written. The function was not judged.',
        'none',
        'Nothing to do: the bot re-verifies the head automatically, and a maintainer looks if it repeats.'),
    'refused_rules': (
        'The unit breaks a mechanical source rule (R38 codegen steering, R39 decompiler leftovers, R40 comment '
        'contents) and was refused before any compare.',
        'counts only if the rule was in docs/code-rules.md at the PR\'s base; none for a newer rule',
        'Fix the line the finding names and push.'),
    'review_rejected': (
        'Both hosts byte-matched, but the review did not approve the source.',
        'none',
        'Read the notes under the function, fix the ground they name and push.'),
    'debt': (
        'The function already failed to match before this PR; it never blocks, is not recorded and is not named in the comment.',
        'none',
        'Nothing is asked of this PR.'),
    'held': (
        'The whole PR was held (a leak finding or a regression of an accepted function); this function was not judged.',
        'none',
        'Read the message above the table, fix what it names and push.'),
}
RULE_REFUSAL = re.compile(r'\b(R3[89]|R40)\b')
RULE_ROW = re.compile(r'^\|\s*(R\d+)\s*\|', re.M)
# Categories (pr_bot.host_category and the Mac host's own) that mean no byte comparison happened.
NOTHING_COMPARED = frozenset({'unbound', 'include', 'compile'})
SHOWN = 20
MARKERS = ('<!-- verdicts:start -->', '<!-- verdicts:end -->')


def rules_in(lines):
    """The R38-R40 codes a list of finding lines names, sorted."""
    return sorted({m.group(1) for line in lines for m in RULE_REFUSAL.finditer(line)})


def rules_in_force(text):
    """The rule codes docs/code-rules.md lists as rows, from its text at some revision."""
    return sorted(set(RULE_ROW.findall(text or '')))


def refusal_counts(rules, base_rules):
    """True when a refusal counts toward the strikes: at least one refused rule existed at the PR's base.

    Without the base's rule list the answer is no: a strike is never assumed.
    """
    return bool(base_rules) and any(rule in set(base_rules) for rule in rules)


def host_category(decision, rva, code):
    why = decision.get('host_why') or {}
    row = why.get(rva) or why.get(str(rva)) or {}
    return row.get(code)


def classify(decision, rva):
    """The kind a function's internal verdict falls under, for the comment and its table."""
    verdict = (decision.get('verdicts') or {}).get(rva)
    if verdict == 'matched':
        # A matched function that a PR-wide hold keeps from merging is not named in the comment, as before.
        return 'matched'
    if verdict == 'debt':
        return 'debt'
    if verdict == 'blocked' or verdict is None:
        return 'held'
    code = verdict.split(':', 1)[-1]
    if code == 'precheck':
        return 'refused_rules' if rules_in((decision.get('pre') or {}).get(rva, [])) else 'unfit'
    if code in ('missing', 'record'):
        return 'needs_review'
    if code == 'review':
        return 'review_rejected'
    if code in ('host1', 'host2'):
        category = host_category(decision, rva, code)
        if category in NOTHING_COMPARED:
            return 'compile_error'
        if category == 'missing':
            return 'needs_review'
        return 'mismatch'
    return 'needs_review'


def strike_text(kind, decision, rva):
    """The strike column for one function; only `refused_rules` depends on the PR."""
    if kind != 'refused_rules':
        return KINDS[kind][1]
    rules = rules_in((decision.get('pre') or {}).get(rva, []))
    if refusal_counts(rules, decision.get('base_rules')):
        return 'counts: ' + ', '.join(rules) + ' was in force at the PR\'s base'
    return 'none: ' + ', '.join(rules) + ' is newer than the PR\'s base, or its base could not be read'


def table_lines(decision, shown=SHOWN):
    """The verdict table for the functions that were not accepted; [] when every function was.

    A matched function has nothing to say and a debt function is never named in the comment."""
    rows = []
    for rva in sorted(decision.get('verdicts') or {}):
        kind = classify(decision, rva)
        if kind not in ('matched', 'debt'):
            rows.append((rva, kind))
    if not rows:
        return []
    lines = ['Verdicts (what each one means and costs: docs/contributor-card.md, "Verdicts"):',
             '', '| Function | Verdict | Strike | Next step |', '| --- | --- | --- | --- |']
    for rva, kind in rows[:shown]:
        lines.append(f'| 0x{rva:x} | `{kind}` | {strike_text(kind, decision, rva)} | {KINDS[kind][2]} |')
    if len(rows) > shown:
        counts = {}
        for _rva, kind in rows[shown:]:
            counts[kind] = counts.get(kind, 0) + 1
        lines.append('| and ' + str(len(rows) - shown) + ' more | ' + ', '.join(f'`{k}` {n}' for k, n in sorted(counts.items()))
                     + ' | see the kinds above | |')
    return lines


def lint_verdict_lines(rules, base_rules):
    """The sentence a PR held for an R38-R40 refusal ends with; [] when no rule refused it."""
    if not rules:
        return []
    counts = refusal_counts(rules, base_rules)
    strike = ('this counts toward your strikes: the rule was already in force at your PR\'s base'
              if counts else 'no strike: the rule is newer than your PR\'s base')
    return [f'Verdict `refused_rules` for the functions of the refused units ({", ".join(rules)}): {strike}.']


def doc_table():
    """The Markdown table docs/contributor-card.md carries between its verdict markers."""
    lines = ['| Verdict | What happened | Strike | Next step |', '| --- | --- | --- | --- |']
    for kind, (meaning, strike, nxt) in KINDS.items():
        lines.append(f'| `{kind}` | {meaning} | {strike} | {nxt} |')
    return '\n'.join(lines)


if __name__ == '__main__':
    print(doc_table())
