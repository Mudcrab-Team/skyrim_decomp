# 0x2a4ca0 ImageSpaceModifierInstanceRB::ctor

<!-- tags: method/diagnostic -->

- Function: 0x2a4ca0 ImageSpaceModifierInstanceRB::ctor
- Label: GUESS(low)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 237/237
- Attempts: 4

## What differed

Instruction bytes matched but the frame was 0x10 larger and the callee-saved saves sat at other offsets. The target passes the address of an unused local to a callee, and that local lives in the caller's shadow space of the fourth register parameter.

## Spellings tried that did not help

A 12-byte `Vec3` local (placed inside the frame, frame 0x60). Passing the address of the parameter itself (forced a spill of the parameter).

## Spelling that fixed it

Declare the out-parameter local as an 8-byte type (`struct Vec2 { float x; float y; };`). The compiler places a local of 8 bytes or less in an unused shadow slot and the frame shrinks to the target size. The base destructor in the unwind funclet needed a bind hint.
