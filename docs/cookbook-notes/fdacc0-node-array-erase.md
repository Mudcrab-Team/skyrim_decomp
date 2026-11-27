# 0xfdacc0 BSPortalGraph::RemoveByPointer

<!-- tags: construct/destructor, construct/loop, abi/exception, wall/register-schedule -->

- Function: 0xfdacc0 BSPortalGraph::RemoveByPointer
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 150/228 aligned matching bytes
- Attempts: 6 comparisons

## What differed

The target releases the element before moving the tail into the hole. With an explicit reference destructor and a named remaining count, the candidate reached the target length. The search and erase retained the graph and index in different registers.

## Spellings tried that did not help

Releasing the raw pointer directly lost the target exception frame. Moving the index search into an array member changed the surrounding register saves and increased the function length.

## Spelling that fixed it

none
