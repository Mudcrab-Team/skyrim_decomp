# 0x157ead0 BSShadowDirectionalLight::Accumulate

<!-- tags: wall/register-schedule, construct/loop, method/diagnostic -->

- Function: 0x157ead0 BSShadowDirectionalLight::Accumulate (also 0x15879d0, 0x1587a30, 0x1587ae0)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: operand-order
- Best score: 208/208 from 193/208
- Attempts: 5

## What differed
After the call set and loop were right, the descriptor address was formed as base plus index in the draft and index plus base in
the target. For the frustum siblings the shift mask was a conditional move in the draft and a branch in the target, and two
float stores came out in the opposite order.

## Spellings tried that did not help
A ternary for the shift mask (always a conditional move), an early-return helper (worse).

## Spelling that fixed it
Directional light: the permuter found it in one round, `decl-move`: declare the cached accumulator pointer before the cascade
local. Frustum mask: an `if (cascade <= 30) { mask = 1 << cascade; } else { mask = 0; }` statement with a named local. Camera
update: assign the far plane before the near plane. Each is a one-line reorder; try them before deeper changes.
