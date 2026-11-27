# 0x1510b60 ShadowSceneNode::UpdateOcclusionPlaneVisibility

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x1510b60 ShadowSceneNode::UpdateOcclusionPlaneVisibility
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 289/289 aligned matching bytes
- Attempts: 4 comparisons

## What differed
The target calls both plane tests on every visible plane and combines the results without a branch, then turns the result
into a state of 1 or 2.

## Spellings tried that did not help
`(inside && front) ? 1 : 2`: the short-circuit adds a branch and skips the second call.

## Spelling that fixed it
Store both results in `bool` locals and write `(inside & front) ? 1 : 2`. The compiler then emits an and, an exclusive-or
with 1 and an increment. The walk over the occlusion shapes is a pointer-list `GetNext(pos)` loop with a stack culler and
a frustum-planes local, both constructed before the loop.
