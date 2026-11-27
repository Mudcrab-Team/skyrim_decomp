# 0x155c6a0 ShadowmapDescriptor::ShadowmapDescriptor

<!-- tags: wall/register-schedule, abi/exception, construct/constructor -->

- Function: 0x155c6a0 ShadowmapDescriptor::ShadowmapDescriptor (also 0x155da30 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::ConstructDefaultItems)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 163/163 bytes with unwind data different (0x155c6a0); 197 of 199 bytes (0x155da30)
- Attempts: 20

## What differed
The two walls from the earlier notes reproduced from a clean unit. The standalone constructor has the right instructions in every position and
only the zero constant sits in a different callee-saved register (the target holds it in r14 and saves, but never uses, rbp; the draft holds it in
rbp); that shows up as an unwind-info mismatch, not a code mismatch. The range construction has the descriptor constructor inlined into its loop and
keeps two advancing pointers (the item pointer that also feeds the allocation cleanup slot, and the item pointer biased by 0xC0 so the field stores
need only byte displacements).

## Spellings tried that did not help
- 0x155c6a0: members assigned in the body instead of an initialiser list, a mixed form with the three leading members in the list and the rest in the body,
  the descriptor destructor declared with and without `noexcept`. All 163 bytes, same register.
- 0x155da30, with the loop body defined in the unit so every shape was a one-line edit: pointer loop with a post-increment (205), pointer loop over an end
  pointer (204), count-down loop on a pointer (204), do-while with a pre-test (204), a pointer loop that also holds the placement result in a local
  (205), index into the buffer (228), index over the start-to-end range (215), `base + start + i` (215 and 197), `pItem + i` (197).
- The bias appears only when the address is formed from the index; then the compiler derives the plain item pointer from the biased one each iteration
  (one induction variable, two bytes short). Pointer forms never bias.

## Spelling that fixed it
none. The unit-side lesson that helps the next attempt: define the range-construction body in the unit (an out-of-class template member definition plus an
explicit instantiation, declared without a body in the header) so each loop shape is a one-line edit; the target most likely advances the item pointer and
the member-address pointer separately because the constructor was inlined from a function that took its object by pointer.
