# 0xff7f50 BSCompoundFrustum::AddOcclusionShapeIfVisible

<!-- tags: abi/virtual, wall/control-flow -->

- Function: 0xff7f50 BSCompoundFrustum::AddOcclusionShapeIfVisible
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: 179/179 aligned matching bytes
- Attempts: 4 comparisons, first local pass on comparison 2

## What differed

The portal path can tail-call portal insertion. The box path updates geometry first and translates the insertion result into the visibility state.

## Spellings tried that did not help

The two-path source passed once it used the existing virtual predicate declaration and the appropriate include recipe. Rechecking with shared shape declarations preserved the result.

## Spelling that fixed it

Keep the optional visibility test inside each shape branch. For the box, initialize the insertion result to false, set it only when the visibility test admits the box, and use it to store the final state.
