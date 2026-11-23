# 0x1d89e0 BGSKeywordForm sub_1d89e0

- Function: 0x1d89e0 BGSKeywordForm sub_1d89e0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 74/104 matching bytes, size 108 vs 104
- Attempts: 8

## What differed

The target keeps the loaded element in its own register and the found flag in the return register with a plain zero-extended index; the candidate loads the element into the return register, so the flag lands elsewhere and the index is copied to a widened register. Rule 44; rule 35 did not close it.

## Spellings tried that did not help

Early return inside the loop plus final compare, the index outside the loop, while with post-increment, pointer arithmetic, a local count.

## Spelling that fixed it

none
