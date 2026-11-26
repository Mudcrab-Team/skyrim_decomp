# 0x528ba0 TESWaterNormals::ctor

<!-- tags: method/diagnostic -->

- Function: 0x528ba0 TESWaterNormals::ctor
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 68/125 aligned
- Attempts: 5

## What differed

The target holds zero in a callee-saved register and the thread-local offset in its own register around a saved and restored thread-local value. The candidate folds the offset into the address and needs no callee-saved register.

## Spellings tried that did not help

A scope object with and without a set value, direct save and restore statements, and every split of the four member assignments between the initializer list and the body.

## Spelling that fixed it

none
