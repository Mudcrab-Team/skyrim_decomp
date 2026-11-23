# 0x1540f70 BSImagespaceShader sub_1540f70

- Function: 0x1540f70 BSImagespaceShader sub_1540f70
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 35/39 bytes matching
- Attempts: 5

## What differed

The target zeroes a register, stores that register into the 8-byte member and returns the same register as the zero result. The candidate stores an immediate zero and re-zeroes the return value. Same family as rule 34 (one result local) and rule 43 (preset zero kept in a register).

## Spellings tried that did not help

Return types void, pointer, int and 64-bit unsigned; a reference-to-pointer member. A single result local (rule 34) was not recorded as tried.

## Spelling that fixed it

none
