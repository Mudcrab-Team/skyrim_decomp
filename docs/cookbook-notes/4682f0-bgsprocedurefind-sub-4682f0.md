# 0x4682f0 BGSProcedureFind sub_4682f0

- Function: 0x4682f0 BGSProcedureFind sub_4682f0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 75/105 bytes matching, size equal
- Attempts: 4

## What differed

Only the two callee-saved registers holding this and the argument block are swapped. An unsigned compare earlier gained two bytes. Rule 12.

## Spellings tried that did not help

Early-return form; a named copy of the arguments.

## Spelling that fixed it

none
