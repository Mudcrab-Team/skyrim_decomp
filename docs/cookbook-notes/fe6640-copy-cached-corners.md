# 0xfe6640 BSOcclusionBox::GetCorners

<!-- tags: wall/inlining, method/binding -->

- Function: 0xfe6640 BSOcclusionBox::GetCorners
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 138/138 aligned matching bytes for the box and 125/125 for the plane
- Attempts: 1 comparison per function

## What differed

Both corner getters refresh their cached vertices before copying them to the caller. The checked copy has a shared invalid-parameter path. Clearing the destination on that path expands differently for the four-corner plane and the eight-corner box.

## Spellings tried that did not help

The same source spelling passed on the first comparison for both sizes.

## Spelling that fixed it

Declare the cache as an array of points and call memcpy_s with the byte size of the whole array for both the destination capacity and the copy length. The compiler emits the appropriate clearing path for each array, including the runtime call in the larger case.
