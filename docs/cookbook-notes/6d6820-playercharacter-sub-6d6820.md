# 0x6d6820 PlayerCharacter sub_6d6820

- Function: 0x6d6820 PlayerCharacter sub_6d6820
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 36/102 matching bytes, size 100 vs 102
- Attempts: 5

## What differed

Identical instructions with callee-saved registers permuted (mask, counter and caster each in another register) and a loop-head nop from the shorter zeroing. Rule 12.

## Spellings tried that did not help

Hoisting the caster, pointer iteration, a while form; merging the conditions changes semantics.

## Spelling that fixed it

none
