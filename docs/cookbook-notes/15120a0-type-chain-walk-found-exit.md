# 0x15120a0 ShadowSceneNode::SetLightNodeFlags

<!-- tags: construct/loop, wall/control-flow, method/sibling -->

- Function: 0x15120a0 ShadowSceneNode::SetLightNodeFlags
- Label: GUESS(low)
- Outcome: fixed
- Cause: loop-shape
- Best score: 241/241 bytes with unwind and exception data
- Attempts: 6

## What differed
A recursive walk over a node's children that tests each child's run-time type chain for the light type, sets or clears a flag
bit and optionally removes the light, otherwise recurses into node children. The first draft had the right logic but three
differences: the child count was re-read each iteration (the target caches it as a 16-bit count and counts down), the type
walk was written as a loop followed by a test of the loop variable (the target jumps from the match straight into the flag code),
and the recursion passed the node-cast result (the target passes the child pointer after testing the cast).

## Spellings tried that did not help
- A 32-bit loop index and bound: the compiler keeps the bound reload.
- The walk as a `while` that stops on match, then `if (type)`: it adds a test after the loop.

## Spelling that fixed it
Read the child count once into a 16-bit local and index with a 16-bit counter; write the type walk as a small helper that
returns true on a match and false at the end of the chain (the sibling's `IsKindOf` shape); and call the recursive function with
the child pointer after `if (child->AsNode())`. The flag edit is `if (set) flags |= 1; else flags &= ~1u;`, which already
compiled to the target's conditional move.
