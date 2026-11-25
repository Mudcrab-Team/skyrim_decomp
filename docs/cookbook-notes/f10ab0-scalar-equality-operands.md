# 0xf10ab0 NiColorExtraData::Functionf10ab0

<!-- tags: construct/float, method/diagnostic, wall/register-schedule -->

- Function: 0xf10ab0 NiColorExtraData::Functionf10ab0
- Label: GUESS(low)
- Outcome: fixed
- Cause: operand-order
- Best score: PASS; 55/55 exact code bytes
- Attempts: 2

## What differed
The handwritten null-guarded four-component equality query compiled to the target instruction count under the existing fast-float recipe. The first ordinary comparison measured 16/55 aligned matching bytes, distance 1.5, with three register-renaming differences. The recipe selection followed cookbook rule 48 because the observed float comparisons omit exceptional-value branches. This does not establish the original build flags.

## Spellings tried that did not help
Putting the other object's component on the left of each inequality left the register residue. A bounded one-worker PC permutation search scored 49 candidates and found an equivalent operand order with distance zero. All ordinary failed evidence and search history remain private.

## Spelling that fixed it
Keep the null guard and early false return, and put this object's component on the left of each inequality. The ordinary comparator passed after applying this authentic symmetric comparison spelling. The analogous vector-payload query at 0xf1a1d0 passed its first ordinary comparison with the same spelling. Both are local candidates only. No sibling middleware body was inspected or adapted.
