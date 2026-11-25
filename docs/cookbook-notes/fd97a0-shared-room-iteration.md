# 0xfd97a0 BSPortalGraphEntry::HasSharedRoomVisibility

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xfd97a0 BSPortalGraphEntry::HasSharedRoomVisibility
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 14/250 aligned matching bytes
- Attempts: 1

## What differed

Two entries can share unbounded space or a room in their accumulation lists. The candidate that searches raw room pointers produces a shorter body.

## Spellings tried that did not help

Checking the empty ranges explicitly and stopping the search at the first common room did not recover the target loop or register saves.

## Spelling that fixed it

None.
