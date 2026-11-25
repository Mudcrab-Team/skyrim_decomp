# 0xce0980 array element removal

<!-- tags: abi/calling-convention, construct/loop, wall/register-schedule, wall/inlining -->

- Function: 0xce0980 array element removal
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: bounded search comparator pass; tidied source is confirmed separately
- Attempts: 4 normal compares and 33 search candidates

## What differed
Destination, source and byte-count locals lengthened three intermediate live ranges. The code reached the correct extent, but the scratch registers and count test width still differed.

## Spellings tried that did not help
Reordering those locals, widening the byte count, and using an unbounded destination extent while retaining the locals.

## Spelling that fixed it
Inline the destination, source and pointer-sized count expressions into the safe-move call. The winning source removes all three temporary locals; the wrapped 32-bit index products and byte count remain explicit before their widening conversions. The search reached zero distance after 33 candidates and passed the comparator; a normal compare of the tidied source supplies the publication evidence.
