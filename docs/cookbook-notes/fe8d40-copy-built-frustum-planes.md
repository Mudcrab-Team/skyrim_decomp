# 0xfe8d40 BSOcclusionPlane::CopyFrustumPlanes

<!-- tags: construct/float, wall/inlining -->

- Function: 0xfe8d40 BSOcclusionPlane::CopyFrustumPlanes
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 247/247 aligned matching bytes
- Attempts: 4 comparisons, first local pass on comparison 1

## What differed

The plane builder runs before the destination receives six planes and the trailing state. Each plane normal is copied one coordinate at a time.

## Spellings tried that did not help

The scalar member copy passed on the first comparison. Reusing it with the full occlusion-plane base preserved the result.

## Spelling that fixed it

Share the plane-set copy operation with the assignment operator. Copy the three normal coordinates and the constant individually, then copy each trailing state field.
