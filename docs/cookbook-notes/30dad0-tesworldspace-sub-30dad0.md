# 0x30dad0 TESWorldSpace sub_30dad0

- Function: 0x30dad0 TESWorldSpace sub_30dad0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 30/54 matching bytes, size 36 vs 54
- Attempts: 8

## What differed

The target repeats the parent-null and use-flag test in the loop body; the compiler folds it to a single test. Rule 41.

## Spellings tried that did not help

Recursion, while with a helper, bool plus ternary helper, early-return helper, explicit break.

## Spelling that fixed it

none
