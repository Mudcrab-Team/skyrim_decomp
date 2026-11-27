# 0x150f3d0 ShadowSceneNode::SetSunLight

<!-- tags: wall/control-flow, construct/allocation, abi/exception -->

- Function: 0x150f3d0 ShadowSceneNode::SetSunLight (also 0x150f580)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: constant-folding
- Best score: 420/420 and 382/382 bytes with unwind and exception data
- Attempts: 9

## What differed
Two light setters delete the old light object, create a new one (or a default light node when the caller gives none) and hand
the node over through a virtual call. After the allocator, once-init guard and constructor shapes matched, both drafts were
two bytes long: the zero register was created after the delete, and the delete flag `1` was a plain constant, where the target
creates the zero first and builds the `1` from it.

## Spellings tried that did not help
- Naming the null in a local, a local for the old pointer, and a local for the created light (seven variants over 0x150f580).
- Moving the default-light branch first.

## Spelling that fixed it
Read the branch that skips the store: the target's "no old light" jump lands after the store of null into the member. So the
store belongs inside the guard, `if (light) { delete light; light = nullptr; }`, not after it. The zero is then needed on the
path that deletes, so it is created before the test and the constant 1 is derived from it. A store that a jump skips belongs to
the block that the jump skips.
