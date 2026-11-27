# 0x14a1250 BSTArray<void*, BSScrapArrayAllocator>::~BSTArray

<!-- tags: wall/control-flow, abi/exception -->

- Function: 0x14a1250 BSTArray<void*, BSScrapArrayAllocator>::~BSTArray
- Label: GUESS(low)
- Outcome: unsolved
- Cause: other
- Best score: 48/59
- Attempts: 5

## What differed
The body is an array destructor on a scrap-heap allocator: release the buffer when there is one, zero the count, then run the base-class count destructor. The target keeps that last call as a plain call with a nop after it and one shared tail for both paths; the draft turns it into a tail jump and duplicates the epilogue, six bytes longer. The CrashLogger name (a ShadowSceneNode light removal) does not fit the body at all.

## Spellings tried that did not help
- Plain element type with the allocator left trivial.
- Empty user-provided destructor on the allocator class.
- Element type with an empty user-provided destructor.

## Spelling that fixed it
none. The target seems to have one more live exception state at the last call (another base or member with a destructor that compiles to nothing); no spelling tried reproduced it.
