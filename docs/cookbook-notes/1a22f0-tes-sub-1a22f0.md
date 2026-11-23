# 0x1a22f0 TES sub_1a22f0

- Function: 0x1a22f0 TES sub_1a22f0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 20/100 aligned bytes, size 85 vs 100
- Attempts: 7

## What differed

Arithmetic and stores are right in value (cell coordinates, half of an unsigned global, a float margin, four shifted sums), but the target computes x+1 and y+1 early, uses a seventh live register and reduces x and y in place; the compiler recomputes x+1 later with fewer registers in every spelling.

## Spellings tried that did not help

Six source orderings: temporaries, a struct, a helper, a setter.

## Spelling that fixed it

none
