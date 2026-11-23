# 0x1812d0 ExtraStartingPosition sub_1812d0

- Function: 0x1812d0 ExtraStartingPosition sub_1812d0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: operand-order
- Best score: 34/46 bytes matching
- Attempts: 5

## What differed

Four 8-byte compares: the first matches in the other-first operand order, the remaining three need this loaded first with a register-memory compare, but every spelling flips either the load order or the compare operands. Rule 42.

## Spellings tried that did not help

Several operand orders.

## Spelling that fixed it

none
