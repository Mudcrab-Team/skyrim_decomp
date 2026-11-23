# 0x1e9fc0 TESLeveledList sub_1e9fc0

- Function: 0x1e9fc0 TESLeveledList sub_1e9fc0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 15/29 bytes matching
- Attempts: 4

## What differed

A form-type check of three values: the candidate always folds the three compares into a subtract and bit test; the target keeps three compares. Rule 41.

## Spellings tried that did not help

Switch, ||, early returns.

## Spelling that fixed it

none
