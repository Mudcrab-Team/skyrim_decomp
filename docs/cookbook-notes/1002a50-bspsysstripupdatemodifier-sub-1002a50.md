# 0x1002a50 BSPSysStripUpdateModifier sub_1002a50

- Function: 0x1002a50 BSPSysStripUpdateModifier sub_1002a50
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 61/65 bytes matching under fpfast
- Attempts: 8

## What differed

Only the false return differs: the target returns a byte-register zero while true is a 32-bit constant; an int return gives a 32-bit zero, bool and char returns give a byte constant for true. Operand order other->updateDeltaTime != updateDeltaTime was already right.

## Spellings tried that did not help

bool, char and int return types.

## Spelling that fixed it

none
