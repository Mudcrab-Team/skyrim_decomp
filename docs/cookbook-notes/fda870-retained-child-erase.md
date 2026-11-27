# 0xfda870 BSPortalGraph::RemoveAlwaysRenderChild

<!-- tags: construct/destructor, construct/loop, abi/exception, wall/register-schedule -->

- Function: 0xfda870 BSPortalGraph::RemoveAlwaysRenderChild
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 177/177 aligned matching bytes
- Attempts: 7 comparisons, first local pass on comparison 3

## What differed

The matched child must remain alive while erasure releases the array reference. The candidate retained it, but the order of pointer storage and the lifetime of the decremented count changed the register saves.

## Spellings tried that did not help

Storing the pointer before taking a reference led to reloads. Retaining first removed those reloads, but the saved-register layout still differed.

## Spelling that fixed it

Retain the incoming pointer before saving it in the temporary reference. In the destructor apply cookbook rule 29 and keep the decremented count in a named unsigned local before testing it.
