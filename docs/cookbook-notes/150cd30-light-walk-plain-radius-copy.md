# 0x150cd30 ShadowSceneNode::AddLightsBelow

<!-- tags: construct/loop, construct/float, abi/virtual -->

- Function: 0x150cd30 ShadowSceneNode::AddLightsBelow
- Label: GUESS(low)
- Outcome: fixed
- Cause: float-codegen
- Best score: 477/477 aligned matching bytes
- Attempts: 1 comparison

## What differed
Nothing on the first comparison. The shape is recorded because it reuses two solved spellings.

A recursive walk over a node's children that returns how many lights it added. Child nodes recurse. For other children, two
inlined run-time type walks (the shared `IsKindOf` loop, then a conditional pointer) select a light and a light subclass. The
light is added with a create-params local whose first byte is set and whose other fields keep their defaults, and it is
updated upwards with a zeroed time-and-flags pair. The subclass gets its three-float radius reset.

## Spellings tried that did not help
none; the first draft matched.

## Spelling that fixed it
- The signature is `(NiNode*, float)`. The float arrives in the third argument register because `this` and the node take
  the first two.
- Write `count += AddLightsBelow(node, r)` for nodes and `++count` after each light, whether or not the subclass test hits.
- The radius store is the plain-copy point from 0x1510eb0: `view->radius = FocusPoint(r, 0.0f, 0.0f);`.
