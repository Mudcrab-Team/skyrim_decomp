# 0xf85a50 NiQuaternionInterpolator::Functionf85a50

<!-- tags: wall/control-flow, construct/float -->

- Function: 0xf85a50 NiQuaternionInterpolator::Functionf85a50
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 69/69 aligned matching bytes; comparator PASS
- Attempts: 2 counted compares, plus 1 binding-only run; 9 permutation candidates

## What differed
The early-return draft reached 55/69 aligned matching bytes with equal instruction counts and no reported behavior mismatches. The remaining differences were classified as branch polarity or block order and reordered instructions. The fast-float recipe was selected before this measured baseline; its effect was not isolated.

## Spellings tried that did not help
The initial spelling returned false when the data pointer was nonnull, then returned the four-component disjunction. It remained a mismatch.

## Spelling that fixed it
The bounded one-worker permutation search found a nested conditional: evaluate the disjunction inside `if (data == 0)` and put `return false` in the `else`. This is the same predicate with a different exit shape, consistent with cookbook rule 2. The tidied spelling passed an ordinary comparison. This is a local candidate pass, not acceptance.
