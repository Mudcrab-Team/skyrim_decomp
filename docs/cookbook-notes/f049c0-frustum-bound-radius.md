# 0xf049c0 BSCullingProcess::CullNodeAgainstFrustum

<!-- tags: construct/float -->

- Function: 0xf049c0 BSCullingProcess::CullNodeAgainstFrustum
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 173/273 aligned matching bytes
- Attempts: 2

## What differed

The zero-radius test precedes the frustum walk. Changing its representation affects both the test and the live values at the subsequent calls.

## Spellings tried that did not help

Comparing the floating-point radius and testing its stored bits as an integer both left a function-size difference.

## Spelling that fixed it

None.
