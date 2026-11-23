# 0x518a30 BGSTerrainNode sub_518a30

- Function: 0x518a30 BGSTerrainNode sub_518a30
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 55/139 bytes matching under fpfast
- Attempts: 4

## What differed

The default recipe gives a double-width fabs mask and a different int-to-float shape; fpfast gives a packed conversion for short-to-float. The target computes both cell centres before the compares. Rule 45.

## Spellings tried that did not help

Both recipes.

## Spelling that fixed it

none
