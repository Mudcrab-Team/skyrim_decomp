# 0x150f930 ShadowSceneNode::GetLuminanceAtPoint

<!-- tags: construct/loop, wall/register-schedule, construct/float -->

- Function: 0x150f930 ShadowSceneNode::GetLuminanceAtPoint
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 423/423 aligned matching bytes
- Attempts: 7 comparisons

## What differed
A by-value iterator `operator!=` in the shared header shifted the callee-saved saves by one home slot, and the sun's
diffuse colour was read component by component.

## Spellings tried that did not help
A by-value `operator!=`, which 0x15121a0 wanted at one point: the saves landed one home slot off.

## Spelling that fixed it
- Range loops over both light arrays with the iterator compared by const reference.
- The second loop keeps its own shadow-mask bit, `bit <<= 1` per light, and tests `light && (mask & bit)`.
- Copy the diffuse colour into a plain `NiColor` local before summing it. That gives the 8-byte load and the stack-routed
  third component of the target. The ambient colour is summed straight from the light.
