# 0x1622de0 UI_listEntry::Function1622de0

<!-- tags: construct/float, wall/register-schedule, method/diagnostic -->

- Function: 0x1622de0 UI_listEntry::Function1622de0
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: 45/58 aligned matching bytes before the fix; PASS 58/58 after
- Attempts: 4 counted comparisons; one bounded permutation search

## What differed
The point query tests both coordinates against a rectangle, then tests the first coordinate against a shared threshold. The initial handwritten draft mistakenly used the second coordinate for that last test. Both compilations had the same instruction shape and length, and alignment classified only register renaming. The target needed the first coordinate to remain live across the second coordinate's bounds checks.

## Spellings tried that did not help
Naming the coordinates where used, then declaring both at entry, left the score at 45/58. A one-worker permutation search exhausted 73 candidates at distance 1.5 without improvement. Register classification alone did not establish that the values carried through those registers were correct.

## Spelling that fixed it
Correct the final predicate to use the first coordinate. The ordinary native comparison then passed 58/58. The declaration names and owner remain inferred stand-ins. This local pass is a candidate, not acceptance.
