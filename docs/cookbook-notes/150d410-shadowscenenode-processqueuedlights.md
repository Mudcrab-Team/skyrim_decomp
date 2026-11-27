# 0x150d410 ShadowSceneNode::ProcessQueuedLights

<!-- tags: abi/exception, wall/inlining, construct/loop -->

- Function: 0x150d410 ShadowSceneNode::ProcessQueuedLights
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 1721/2007 aligned bytes
- Attempts: 5

## What differed
The structure was right on the first compile (1614 aligned bytes): the queued-add walk with the memory-context scope, the two queue walks, the two object lists with the node/geometry split, the six array clears and the prune loop with `erase`. What moved the score: comparing the existing light's node with the new one in the target's operand order, the negated `!(fade >= limit)` test (a float constant held in a callee-saved register across the loops, which adds the frame's vector-register save), and defining the neighbouring `UnlinkLight` body in the unit so the compiler knows the smart-pointer copy survives the call. Still open: the literal value of the fade limit (1.0f is a guess that binds as a different literal), the frame size, and the smart-pointer copy around `UnlinkLight` still being re-read from the stack.

## Spellings tried that did not help
- A named extern float for the limit: loaded inside the loop instead of hoisted.

## Spelling that fixed it
none.
