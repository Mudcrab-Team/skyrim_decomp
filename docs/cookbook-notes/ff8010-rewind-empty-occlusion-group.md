# 0xff8010 BSCompoundFrustum::AddOcclusionShapeToGroup

<!-- tags: wall/register-schedule -->

- Function: 0xff8010 BSCompoundFrustum::AddOcclusionShapeToGroup
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: operand-order
- Best score: 268/268 aligned matching bytes
- Attempts: 3

## What differed

An occlusion box can leave a newly opened group empty. The decision to discard it compares a saved operator index to its current value.

## Spellings tried that did not help

Putting the current member on the left of the equality changed the compare without changing the behavior.

## Spelling that fixed it

Save the index before adding the box and put that saved value on the left when comparing it with the current index.
