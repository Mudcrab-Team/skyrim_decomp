# 0x1511980 ShadowSceneNode::ResetScene

<!-- tags: wall/register-schedule, construct/loop -->

- Function: 0x1511980 ShadowSceneNode::ResetScene
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 996/1351 aligned bytes (distance 44 on the cleanest draft)
- Attempts: 4

## What differed

The structure matches from the first draft: two out-of-line lock guards, six array clears, a walk over the portal graph with a find-and-remove on
each cell array and a list teardown, then three calls and the graph store. What stays different is how the inlined array helpers address the array
fields. The target reads the size and the buffer at fixed offsets from the owning object and forms the address of the size field only on the cold
path, just before the shift call. The draft forms that address once, before the first size load, and keeps it in a callee-saved register, which
shifts every later register choice. The same happens to the last array free, where the draft keeps the address of the array and the target keeps
the owner. The minus-one constant also lives in other registers.

## Spellings tried that did not help

- A signed count with a positive guard and an unsigned loop: it fixed the loop form but not the addressing.
- The size copied into a local at the top of the removal helper: no change.
- The owner of the last array read into a local first: a much worse register picture (extra spill of this, larger frame).
- Incrementing the walk iterator right after the load instead of in the loop header: this one was kept, it matches the target.

## Spelling that fixed it

none
