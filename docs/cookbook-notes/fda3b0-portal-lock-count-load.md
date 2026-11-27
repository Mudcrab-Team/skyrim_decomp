# 0xfda3b0 BSPortalGraph::StageAlwaysRenderChildAdd

<!-- tags: wall/register-schedule -->

- Function: 0xfda3b0 BSPortalGraph::StageAlwaysRenderChildAdd
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 285/285 aligned matching bytes
- Attempts: 4

## What differed

The pending-list searches agreed. Unlocking still loaded the recursion count separately at its last-release test.

## Spellings tried that did not help

Rewriting the index search preserved the extra load.

## Spelling that fixed it

Use the ordinary count member and the interlocked operations for the updates. The last-release test then compares the field in place.
