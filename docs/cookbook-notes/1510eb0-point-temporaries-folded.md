# 0x1510eb0 ShadowSceneNode::SetFocusFrustum

<!-- tags: wall/constant, construct/float, abi/exception -->

- Function: 0x1510eb0 ShadowSceneNode::SetFocusFrustum (also 0x150cd30, 0x150f930, 0x1510b60)
- Label: GUESS(low)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 396 of 433 bytes (structure and control flow equal)
- Attempts: 3

## What differed
Under a memory-context scope the function either takes the caller's frustum object or builds a default one (class allocator,
constructor, smart-pointer assignment) and fills it: six float constants through one reload of the smart pointer, then three
point members, each from a temporary in a stack slot with the first two components packed through a vector register. The draft
matches the allocator, guard, smart-pointer and branch shapes, but its point assignments fold to direct constant stores.

## Spellings tried that did not help
`NiPoint3{...}` and a three-argument constructor for the temporary, a local for the frustum pointer.

## Spelling that fixed it
none. Not drafted at all: 0x150cd30 (recursive scene walk with a local parameter block, run-time type casts with conditional
moves and float spills), 0x150f930 (float luminance gathering with a counted light loop) and 0x1510b60 (a 6-plane local array,
a local object built from the camera and a portal room walk with unknown callees).
