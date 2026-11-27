# 0xeeae90 NiAVObject::GetExtraDataByName_140C60AD0

<!-- tags: wall/register-schedule, abi/exception -->

- Function: 0xeeae90 NiAVObject::GetExtraDataByName_140C60AD0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 186/222 (aligned_matching_bytes)
- Attempts: 6

## What differed

The candidate reproduced the exact size, all sixty-eight instruction shapes, and the C++ exception-handling unwind metadata for the scoped read lock, but swapped the two callee-saved registers assigned to the object pointer and the sign-extended midpoint index inside the binary-search loop.

## Spellings tried that did not help

- Loading the search key into a local pointer before calling the element name getter inside a signed sixteen-bit binary search under a scoped read-lock guard.
- Rewriting the non-empty check as an early return and reversing the negative/positive comparison branch order (increased function size).
- Removing the local key pointer temporary and subtracting directly (reduced function size).
- Reordering the low and high endpoint declarations and storing the midpoint in a signed sixty-four-bit index variable.

## Spelling that fixed it

none
