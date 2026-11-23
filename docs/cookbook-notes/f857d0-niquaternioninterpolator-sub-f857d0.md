# 0xf857d0 NiQuaternionInterpolator sub_f857d0

- Function: 0xf857d0 NiQuaternionInterpolator sub_f857d0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 49/61 bytes matching
- Attempts: 5

## What differed

In the constructor taking a const reference to a quaternion, the target loads the 16-byte value right after the base constructor call and before the vtable store; every order tried leaves the load after the vtable store or at the end. Cited in rule 42.

## Spellings tried that did not help

Initialiser list; body assignment before and after zeroing.

## Spelling that fixed it

none
