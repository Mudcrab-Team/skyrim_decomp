# 0x11e22c0 BSNavmesh::GetGridBounds

<!-- tags: construct/float, method/diagnostic, method/sibling, sibling/f3, wall/inlining -->

- Function: 0x11e22c0 BSNavmesh::GetGridBounds
- Label: GUESS(low)
- Outcome: fixed
- Cause: inlining
- Best score: 51/87 aligned matching bytes before the fix; 87/87 and comparator PASS after
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
Default aggregate assignment merged adjacent point components into wider copies. The target retained three separate scalar copies for each output point. The fast floating-point recipe already supplied the required comparison behavior.

## Spellings tried that did not help
Implicit aggregate point assignment produced a shorter function. No additional floating-point recipe change was needed.

## Spelling that fixed it
Give the point type a component-wise assignment operator and keep whole-point assignment at both call sites. The operator follows the labelled Fallout 3 sibling body in the header. This is the same source-shape lead recorded by the existing point-assignment lesson for NiNode::UpdateDownwardPass. The final comparison passed after provenance was completed.
