# 0x14f320 IngredientItem sub_14f320

- Function: 0x14f320 IngredientItem sub_14f320
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 66/123 bytes matching, size 134 to 163 vs 123
- Attempts: 3

## What differed

Static array teardown loop with a shared epilogue; the candidate duplicates the epilogue and uses different callee-saved registers.

## Spellings tried that did not help

The result line records no specific spellings.

## Spelling that fixed it

none
