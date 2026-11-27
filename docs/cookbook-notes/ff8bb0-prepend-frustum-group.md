# 0xff8bb0 BSCompoundFrustum::PrependUnionGroupStart

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xff8bb0 BSCompoundFrustum::PrependUnionGroupStart
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 253/301 aligned matching bytes
- Attempts: 3

## What differed

The union and intersection variants both grow storage and shift existing operations to open the first slot. Their capacity checks and index lifetime diverge after the nesting scan.

## Spellings tried that did not help

Caching the old end, refreshing it after growth, and separating the second room check from the shift all left a shorter body. The same result occurred at 0xff8cf0.

## Spelling that fixed it

None.
