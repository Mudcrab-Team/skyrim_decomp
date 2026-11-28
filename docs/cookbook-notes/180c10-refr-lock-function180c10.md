# 0x180c10 REFR_LOCK::Function180c10

<!-- tags: method/diagnostic -->

- Function: 0x180c10 REFR_LOCK::Function180c10
- Label: GUESS(low)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 169/174 (aligned_matching_bytes)
- Attempts: 6

## What differed

Every control-flow branch, clamp, and constant in the lock-level calculation matched, except the compiler scheduled the constant load for the upper bound clamp ahead of adding the scaled offset into the running sum, swapping the two operands of the multiply-and-add step.

## Spellings tried that did not help

- Computing the scaled offset in a separate local integer before adding it to the base level.
- Using an inline clamping helper function with separate lower and upper bound checks.
- Writing the level scaling with a signed integer multiplier versus an unsigned integer multiplier.
- Splitting the leveled branch into early returns versus assigning into a shared result variable.

## Spelling that fixed it

none
