# 0xfd95c0 BSPortalGraphEntry::AddRoomToAccumList

<!-- tags: construct/loop, construct/constructor, wall/register-schedule -->

- Function: 0xfd95c0 BSPortalGraphEntry::AddRoomToAccumList
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 159/203 aligned matching bytes
- Attempts: 6 comparisons

## What differed

The candidate finds an existing room and retains a new room across array growth. Its destination construction differs after the index reservation. The target stores the pointer again after retaining a non-null room.

## Spellings tried that did not help

A named append helper and an explicit reference temporary kept the first score. A copy constructor and separate allocator and count bases changed the register saves and reduced the score.

## Spelling that fixed it

none
