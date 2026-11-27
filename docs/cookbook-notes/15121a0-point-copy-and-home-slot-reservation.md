# 0x15121a0 ShadowSceneNode::UpdateLightList

<!-- tags: wall/register-schedule, abi/exception, construct/loop -->

- Function: 0x15121a0 ShadowSceneNode::UpdateLightList
- Label: GUESS(low)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 305 of 301 bytes (313 of 301 at the start of the round)
- Attempts: 5

## What differed
The loop body and calls match. Two things differ: the prologue saves four callee-saved registers into incoming-argument home
slots in the draft, and only two (plus three pushes) in the target, which also skips the second and fourth home slots; and the
light position copy is three float loads then three float stores in the target, but the draft interleaves them and moves one
component through an integer register.

## Spellings tried that did not help
- The position as three float locals: one component still goes through an integer register.
- Permuter: best distance 15.5, unchanged.

## Spelling that fixed it
Partly. `light->position = node->boundCenter;` (the member-wise copy) saves 8 bytes, and writing the "list is empty" iterator
with the inverted test (`if (!size) null else element`) matches the target's branch polarity. The remaining home-slot pattern is
like the incoming-slot-skipped family (rule 29): a named local that the compiler reserves a slot for and then drops.
