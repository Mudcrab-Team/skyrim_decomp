# 0xf61440 NiFloatInterpolator::SaveBinary

<!-- tags: abi/calling-convention, construct/serialization, method/diagnostic, wall/callee -->

- Function: 0xf61440 NiFloatInterpolator::SaveBinary
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: calling-convention
- Best score: 102/102 code bytes; comparator PASS, unwind covered
- Attempts: 3 counted comparisons on this lead

## What differed
The draft matched the base call, the component-size stack local, the write through the stream's function pointer and the byte counter update. It differed only at the end: the target jumps into the link-id writer as a tail call, the draft called it and returned, which shifted the epilogue.

## Spellings tried that did not help
- The component-size local sat at function scope for the whole body. Its address is passed to the write callback, and an address-taken local that is still in scope blocks the tail jump.

## Spelling that fixed it
Wrap the component-size local and the counted write in a block. The link-id call after the block compiles to the tail jump and the whole function matches. Same mechanism as 0x7a3ec0 and 0xef2830's sibling write helpers: scope address-taken locals tightly when the target ends in a tail jump.
