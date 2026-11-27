# 0x23bcd0 InventoryChanges::AddCountToExistingEntry

<!-- tags: abi/exception, construct/loop, construct/destructor, wall/control-flow -->

- Function: 0x23bcd0 InventoryChanges::AddCountToExistingEntry
- Label: GUESS(low)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 58/82 matching bytes; distance 5.0; comparator FAIL, function-size-mismatch (67/82 bytes)
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The linked-list search and count update compile without the target's exception-state frame. The candidate is fifteen bytes shorter. All four comparisons measured the same score and distance. Cookbook rule 13 describes the remaining exception-state shape; the source-only cause remains unresolved. The method name is a behavior guess.

## Spellings tried that did not help

- A direct node-pointer search with a boolean continuation flag gave 58/82 matching bytes.
- A minimal iterator with an explicit destructor that clears its current node gave the same score.
- Removing explicit nonthrowing annotations from the iterator methods also left the score unchanged.

- Structural pass: a local visitor object with a virtual destructor and an inline virtual predicate (devirtualised and inlined by the compiler) does not create the exception-state slot; the slot of the neighbouring visitor units (0x5d18b0, 0x5d1400) appears only when a virtual Accept call survives.

## Spelling that fixed it

None. The direct search is retained privately as the simplest best candidate, with its exact-source PC report. The iterator trials and diagnostics remain private. No recipe or comparator changes were made; this is not a comparator pass.
