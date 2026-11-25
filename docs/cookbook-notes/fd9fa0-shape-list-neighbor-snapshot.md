# 0xfd9fa0 BSPortalGraph::RemoveOcclusionShape

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0xfd9fa0 BSPortalGraph::RemoveOcclusionShape
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 208/208 aligned matching bytes
- Attempts: 7 comparisons, first local pass on comparison 4

## What differed

The middle-item unlink reloaded its links after writing through the first neighbor. The target keeps both neighbors available through the two link updates.

## Spellings tried that did not help

One disposal point for all three list positions also changed the head and tail branches. Giving each removal path its own call to the inline disposal helper restored their shape but left the neighbor reloads.

## Spelling that fixed it

Read both neighboring pointers before modifying either one. Link the saved neighbors together and then dispose of the removed item.
