# 0x1ba8e0 Obj1ba8e0::Function1ba8e0

<!-- tags: method/diagnostic -->

- Function: 0x1ba8e0 Obj1ba8e0::Function1ba8e0
- Label: GUESS(low)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 148/150 (aligned_matching_bytes)
- Attempts: 3

## What differed

All 45 preceding instructions of the array search and element shift matched at exact size, except the final size decrement emitted a standalone memory decrement instead of adding the already-live negative-one constant register into the stored count.

## Spellings tried that did not help

- Writing the trailing count update with `-= 1`.
- Writing the trailing count update by adding a negative-one unsigned value.
- Writing the trailing count update as `size = size - 1`.

## Spelling that fixed it

none
