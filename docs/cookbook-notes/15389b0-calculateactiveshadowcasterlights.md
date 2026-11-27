# 0x15389b0 CalculateActiveShadowCasterLights

<!-- tags: wall/control-flow, construct/float -->

- Function: 0x15389b0 CalculateActiveShadowCasterLights
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 690/1354 aligned bytes, size 1336/1354 (fast-float recipe)
- Attempts: 3

## What differed

First draft only. The call set and the loop skeleton match: the directional light first, the focus candidate pass, then each shadow light that
passes the camera and culling checks gets its caster slot, a view-space bound test, a projected rectangle and four integer scissor fields. With
the default float recipe the square root is a library call, so the unit needs the fast-float recipe. Remaining differences: the target keeps the
three float constants and the minus-one in callee-saved vector registers for the whole loop where the draft stores immediates, the two point
locals sit in the other order in the frame, and the culling-check chain is laid out with one shared cleanup block.

## Spellings tried that did not help

- Declaring the two bound points in the other order: the same frame layout.

## Spelling that fixed it

none
