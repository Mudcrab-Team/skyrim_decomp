# 0xce3360 BSReadWriteLock sub_ce3360

- Function: 0xce3360 BSReadWriteLock sub_ce3360
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 82/102 bytes matching, size equal
- Attempts: 5

## What differed

The code matches except that the two callee-saved register spill slots sit one home slot lower than in the target, so the unwind info differs. This is rule 29 (saves that skip the first home slot) rather than rule 12; see rule 29 for the reference-count variant.

## Spellings tried that did not help

Early return versus else, a local thread id, inverted branch, ternary for the sleep argument.

## Spelling that fixed it

none
