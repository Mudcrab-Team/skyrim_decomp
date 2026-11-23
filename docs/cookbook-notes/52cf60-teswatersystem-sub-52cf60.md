# 0x52cf60 TESWaterSystem sub_52cf60

- Function: 0x52cf60 TESWaterSystem sub_52cf60
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 82/94 bytes matching
- Attempts: 6

## What differed

The target keeps two separate per-iteration bit tests with the array reloaded. The best spelling (a byte flag parameter and items[i] used directly) reached 82 bytes with the loads merged; a bool parameter collapsed the function.

## Spellings tried that did not help

Byte-versus-bool parameter, direct element use.

## Spelling that fixed it

none
