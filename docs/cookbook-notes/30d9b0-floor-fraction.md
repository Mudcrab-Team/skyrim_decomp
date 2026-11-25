# 0x30d9b0 TESWorldSpace::Function30d9b0

<!-- tags: construct/float, wall/inlining -->

- Function: 0x30d9b0 TESWorldSpace::Function30d9b0
- Label: CRASHLOGGER_PDB(59818@2026.10.24); Function30d9b0: GUESS(low)
- Outcome: fixed
- Cause: float-codegen
- Best score: 95/95 code bytes; comparator PASS, unwind none in range
- Attempts: 4 counted comparisons on this lead (plus earlier history)

## What differed
Two floor-and-shift computations on the two world coordinates. Under /fp:precise the draft's `x -= 1.0f` after a conditional compiled to an add of a negated constant, while the target subtracts the shared 1.0 constant; both loads of the constant were hoisted the same way.

## Spellings tried that did not help
- `x = x - 1.0f`, `--x` and the original `x -= 1.0f` inside an `if`: all produced the add form.

## Spelling that fixed it
Write the floor once as an inline helper that picks between the truncated value and the decremented value with a conditional expression, then shift: `float floored = value - truncated >= 0.0f ? truncated : truncated - 1.0f;`. The select form keeps the subtraction as written. Call the helper for x and y.
