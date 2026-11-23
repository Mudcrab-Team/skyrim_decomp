# 0x329980 BGSSoundCategory sub_329980

- Function: 0x329980 BGSSoundCategory sub_329980
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: operand-order
- Best score: 57/76 matching bytes (73/76 size) at attempt 6
- Attempts: 10

## What differed

The null-parent and call paths match with the cast outside the ternary. The target loads its own attenuation into a register after the call and adds in 16 bits; the candidate folds the load into the add and flips the clamp compare direction.

## Spellings tried that did not help

Moving the load earlier and later, a min-style select, named locals.

## Spelling that fixed it

none
