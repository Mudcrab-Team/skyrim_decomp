# 0xfda080 BSPortalGraph::AddRoom

<!-- tags: construct/allocation, wall/register-schedule -->

- Function: 0xfda080 BSPortalGraph::AddRoom
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 167/171 aligned matching bytes
- Attempts: 6 comparisons

## What differed

The best candidate has the target length. The last difference is the order of preparing the count subobject and the element size for the index reservation.

## Spellings tried that did not help

An inline append on the room array eliminated the extra graph pointer. Naming the capacity left the same ordering. Splitting the array storage and count into bases changed the search registers.

## Spelling that fixed it

none
