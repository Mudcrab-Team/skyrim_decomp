# 0x150dbf0 ShadowSceneNode::RemoveLightAssociations

<!-- tags: wall/control-flow, construct/loop -->

- Function: 0x150dbf0 ShadowSceneNode::RemoveLightAssociations
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 483/1094 aligned bytes, size 1092/1094
- Attempts: 7

## What differed

Everything outside the inlined spin-lock acquire matches in shape: the guard with the out-of-line constructor, the unlink of each queued light with the
removal from the pending array by swapping in the tail, the object loop with the geometry or node split, and the list clears. The acquire differs in
the same way as in the two other shadow functions that hold this guard (0x98a3c0 and the volumetric render). The target tests each compare-exchange
through a stored flag, takes the first success past the fence, and shares one sleep call whose delay is zero while the spin count is under the limit
(the count is only incremented there) and one above it. The draft gets direct flag branches and a branch-free count and delay.

## Spellings tried that did not help

- The delay as a variable set in an if/else, and as two sleep calls in a do-while: the count update stays branch-free or the compare moves to the loop head.
- The compare-exchange through a std::atomic on a cast pointer: no flag is stored either.
- A by-value iterator for the removal and a visible body for the callee that unlinks the light: the first changed nothing, the second removed a
  re-test of the smart pointer in the loop and was kept.

## Spelling that fixed it

none
