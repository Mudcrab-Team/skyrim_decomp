# 0x155c750 BSShadowLight::ReleaseShadowmapDescriptor

<!-- tags: wall/register-schedule, abi/calling-convention, abi/exception -->

- Function: 0x155c750 BSShadowLight::ReleaseShadowmapDescriptor (also 0x155c850, 0x155d970, 0x155dc00, 0x155d830, 0x155c6a0)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: code identical, size equal; the comparator stops at the unwind info
- Attempts: 6

## What differed
In six functions the instruction stream is the same as the target, byte for byte in size, and only the unwind info
differs: the first callee-saved register is saved in a different incoming-argument home slot. The target skips one slot (the
second argument's home in four of them, the first in the destructor) and uses the next; the draft takes the lowest free one.
The permuter and a `const` parameter did not change it.

## Spellings tried that did not help
- A `const` index parameter, a 64-bit index, reordering the locals.
- The permuter (distance never moved: there is no source site inside the body).

## Spelling that fixed it
none. A different local or parameter set in the original probably reserves that slot; `BSTArray::ConstructDefaultItems`
(0x155da30) also keeps a second, biased element pointer in the target. Worth testing with the sibling container's exact
`SetSize` and a default constructor spelled with member initialisers.
