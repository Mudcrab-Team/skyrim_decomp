# 0x4e0060 PathingCell::Write

<!-- tags: wall/register-schedule, construct/serialization, sibling/fo4 -->

- Function: 0x4e0060 PathingCell::Write
- Label: none
- Outcome: unsolved
- Cause: register-allocation
- Best score: 31/71
- Attempts: 5

## What differed

Every instruction and call slot matches. Only the two callee-saved registers are swapped: the target keeps the stream pointer in the first-chosen register and `this` in the second, the candidate does the opposite. The function writes the world space id through a virtual stream call, then branches on the same field and writes the cell id through one of two other slots in a tail jump. The size is equal, so this looks like register-only residue for the permuter.

## Spellings tried that did not help

- Copy the world space id into a local before the first call (the compare then tests a register, which the target does not).
- Hold the stream in a local pointer and invert the branch (worse, 21 of 71 bytes).
- Bind the info member to a local reference and use it for all reads (same 31 of 71).

## Spelling that fixed it

none
