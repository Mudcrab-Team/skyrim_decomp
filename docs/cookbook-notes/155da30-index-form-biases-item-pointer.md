# 0x155da30 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::ConstructDefaultItems

<!-- tags: wall/register-schedule, construct/constructor, construct/loop -->

- Function: 0x155da30 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::ConstructDefaultItems (also 0x155c6a0)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 197 of 199 bytes (index form); 205 of 199 (pointer form); 0x155c6a0 163/163 with the unwind info different
- Attempts: 9

## What differed
The target builds each descriptor with every field address taken from a second pointer that sits 0xC0 above the item, which
makes the field stores 8-bit displacements, and keeps the plain item pointer too (stored to the new-expression cleanup slot and
advanced by the element size). The standalone constructor (0x155c6a0) saves one more callee-saved register than it uses and
keeps the zero constant in a third one, as if the same biased pointer had been planned and then dropped.

## Spellings tried that did not help
- The pointer-increment loop (the pool header's form): no bias at all, 205 bytes.
- Value initialisation, a `while` over an end pointer, a `for` over pointers, a reference to the item: 204 to 222 bytes.

## Spelling that fixed it
none. Writing the placement address as `base + start + i` makes the compiler create the biased pointer (197 bytes), but then
it derives the item address from the bias inside the loop and has one induction variable where the target has two. The target
probably keeps both an explicitly advanced item pointer and a derived address of a member.
