# 0x1510eb0 ShadowSceneNode::SetFocusFrustum

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x1510eb0 ShadowSceneNode::SetFocusFrustum
- Label: GUESS(low)
- Outcome: fixed
- Cause: float-codegen
- Best score: 433/433 aligned matching bytes
- Attempts: 1 comparison this round

## What differed
The earlier round folded the point temporaries: the draft stored the three components separately, while the target writes
an 8-byte pair and then a 4-byte component that passes through the stack.

## Spellings tried that did not help
The centres as `NiPoint3` with the member-wise `operator=`: the components were stored one by one.

## Spelling that fixed it
Type the frustum centres as a small plain-copy point struct with a three-float constructor and no user `operator=` (here
`FocusPoint`), and assign `centre = FocusPoint(x, y, z);`. The implicit copy of a constructed temporary produces the pair
store plus the stack-routed last component. The same type fixed 0x150cd30.
