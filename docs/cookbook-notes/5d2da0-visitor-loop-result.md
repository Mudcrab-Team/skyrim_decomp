# 0x5d2da0 MagicTarget::FindFirstEffectWithArchetype

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x5d2da0 MagicTarget::FindFirstEffectWithArchetype
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 119/143 aligned bytes
- Attempts: 2

## What differed
The candidate is 137 bytes for a 143-byte target range. The remaining alignment classes include branch polarity and three missing instructions. The comparison suggests a two-way-check spelling; it is not a register-only wall.

## Spellings tried that did not help
Breaking immediately when an effect matched scored 23/143. Keeping the selected effect as loop state and testing it at the start of the following iteration improved to 119/143. That variant still differs; a repeated pointer-test explanation was not established.

## Spelling that fixed it
none
