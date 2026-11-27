# 0x1587f90 BSShadowParabolicLight::BSShadowParabolicLight

<!-- tags: wall/register-schedule, construct/constructor -->

- Function: 0x1587f90 BSShadowParabolicLight::BSShadowParabolicLight
- Label: CRASHLOGGER_PDB(59818@2026.10.24); GUESS(low)
- Outcome: unsolved
- Cause: operand-order
- Best score: 1473/1473 bytes, one temporary vector register pair numbered the other way round
- Attempts: 15

## What differed

Everything matches except four loads at the top of the per-descriptor loop (three counts and the camera pointer): the target adds the scaled element offset first and the buffer pointer second inside the address, the draft has them the other way round. The following stores through a re-read buffer pointer already agree, so the difference comes from how the shared buffer register is combined with the offset in the first group. The viewport store is a four-lane insert sequence that the plain struct with three computed fields and a zero left edge reproduces exactly, once the zero store and the reciprocal sit inside the loop body (the compiler hoists them after the loop guard by itself).

## Spellings tried that did not help

- Declaring the scale and the viewport before the loop: the hoisted divide then sat ahead of the guard (a 56-byte miss), moving them into the loop body fixed it.
- Binding a const reference to the element and reading the counts and camera through it: the compiler hoisted the buffer load out of the first group and the byte count fell.
- The permuter ran 481 candidates and kept the draft as its best.

- A reference to the array and a const reference to the element: the buffer load stayed inside the group, no gain.
- Byte-offset arithmetic written inside the element accessor after the buffer: the order of the four loads did not change.
- Pointer plus index written index first: no change either; the front end reduces both to the same tree.

## What moved the address order

Computing the scaled element offset into a named local before the buffer pointer is read, and adding the buffer to it afterwards, flips the order of the operands in the loads that share the address; this fixed the four loads. Done in the accessor for every use it also flipped the later pointer-chasing group (which already agreed), and it changed which vector register the viewport temporary gets. Using the flipped accessor only through a const reference for the first group (the reads of the counts and the camera) fixed all address orders and left a single swapped register pair in the viewport build (distance 1). Writing the camera store through the non-const accessor or naming the three scaled values first made it worse.

## Spelling that fixed it

none (the address order is controlled by the evaluation order of the offset; the last register pair is open)

## Last register pair (fifth-round sweep)

The remaining difference is the vector temporary of the per-viewport rectangle build: the scalar for the last inserted lane and the vector that
collects the lanes exchange two vector registers. Five reorderings of the loop body (the scale computed before the rectangle, the fields assigned
in reverse order, the three scaled values named first, the multiply operands swapped, only the last value named) and a 401-candidate permuter run
(best distance 1.0, unchanged) left the exchange as it is; one variant moved it to a four-register rotation (worse).
