# 0x5e70e0 ValueModifierEffect sub_5e70e0

- Function: 0x5e70e0 ValueModifierEffect sub_5e70e0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 67/76 bytes matching
- Attempts: 5

## What differed

The target reloads the object pointer from the vtable load into a second scratch register for the spell-type virtual call; the candidate reuses the first register. Same vtable-pointer register reuse as 0x9ff790; no rule yet.

## Spellings tried that did not help

Switch, compare chain, ternary and accessor-function spellings of the type test.

## Spelling that fixed it

none
