# 0x306c10 TESWaterForm::InitItemImpl

<!-- tags: method/diagnostic -->

- Function: 0x306c10 TESWaterForm::InitItemImpl
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 671/868 (aligned_matching_bytes)
- Attempts: 6

## What differed

Using `TestBit` and `!(mag - truncatedF >= 0.0f)` aligned the prologue, the float floor logic and the trailing field resolution, while the effect-search loop allocated different volatile scratch registers for `contactSpell`, `item`, and `baseEffect`, adding `16` bytes (`884` vs `868`).

## Spellings tried that did not help

- Writing `mag - truncatedF < 0.0f` swapped float compare operands; inverting with `!(... >= 0.0f)` fixed operand order.
- Moving the early exit from the `for` condition to `if (found) break;` kept the same register allocation.

## Spelling that fixed it

none
