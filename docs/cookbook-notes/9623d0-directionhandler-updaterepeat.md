# 0x9623d0 DirectionHandler::UpdateRepeat

<!-- tags: method/diagnostic -->

- Function: 0x9623d0 DirectionHandler::UpdateRepeat
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: 78/78 (aligned_matching_bytes)
- Attempts: 4

## What differed

Under the default `/fp:precise` recipe, clamping `ratio` to `1.0f` loaded the `1.0f` constant into a register before the minimum instruction, adding 4 bytes and shifting the XMM registers.

## Spellings tried that did not help

- `if (ratio > 1.0f) ratio = 1.0f;` under default `/fp:precise`: preloaded `1.0f` into a register to preserve NaN semantics.
- `if (ratio >= 1.0f) ratio = 1.0f;` under default `/fp:precise`: kept the same register preload.
- `ratio = (ratio < 1.0f) ? ratio : 1.0f;` under default `/fp:precise`: grew to 86 bytes with an explicit branch.

## Spelling that fixed it

Switch the unit to `reconstruction/recipes/o2-fpfast.json` with `if (time > nextRepeatTime)` and `if (ratio > 1.0f) { ratio = 1.0f; }`: MSVC then folds the clamp into a single memory-operand minimum instruction.
