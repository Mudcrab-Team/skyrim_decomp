# 0x1502e0 MagicItem::Function1502e0

<!-- tags: construct/switch, wall/control-flow -->

- Function: 0x1502e0 MagicItem::Function1502e0
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: PC comparator PASS (all checks passed)
- Attempts: 3

## What differed

A virtual category query excludes three adjacent values. The range predicate selected a different arithmetic form.

## Spellings tried that did not help

Direct lower and upper range comparisons retained the arithmetic difference.

## Spelling that fixed it

Express the excluded finite categories as switch cases with a common false result and a true default.
