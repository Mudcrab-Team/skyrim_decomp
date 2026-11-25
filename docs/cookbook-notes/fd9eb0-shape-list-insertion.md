# 0xfd9eb0 BSPortalGraph::AddOcclusionShape

<!-- tags: construct/allocation, construct/loop, wall/inlining -->

- Function: 0xfd9eb0 BSPortalGraph::AddOcclusionShape
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 220/220 aligned matching bytes
- Attempts: 7 comparisons, first local pass on comparison 4

## What differed

A direct list scan allowed the compiler to combine comparison and traversal. The throwing list-item constructor also preserved an allocation spill and redundant initial stores.

## Spellings tried that did not help

Saving the item in a local before comparing its member shortened the scan. Extracting the traversal step fixed the scan, but the allocation spill remained.

## Spelling that fixed it

Have the traversal helper advance the position and return the element by reference. Mark the pointer-only item constructor noexcept. Both the traversal and append then have the target shape.
