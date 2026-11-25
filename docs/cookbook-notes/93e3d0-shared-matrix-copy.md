# 0x93e3d0 Inventory3DManager::GetModelRotation

<!-- tags: wall/register-schedule, construct/vector -->

- Function: 0x93e3d0 Inventory3DManager::GetModelRotation
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 65/86 aligned matching bytes; distance 4.5; candidate size 82 versus target 86
- Attempts: 5 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The candidate retains the model count from its first test. The target tests the member directly and reads it again after selecting array storage. That changes the count decrement and register lifetimes. Sharing the matrix-copy exit improved the first score from 42/86 to 65/86 aligned matching bytes.

## Spellings tried that did not help
Separate value returns duplicated the matrix copy and produced a 110-byte function. Initializing the fallback pointer before the condition scored 56/86. Selecting array storage before a conditional reference scored 57/86. A bounded single-job permutation search tested 225 candidates and retained distance 4.5 without a zero-distance winner.

## Spelling that fixed it
None. The best original spelling selects a matrix pointer in two branches, then returns one value copy. The final comparison reproduced 65/86 and stopped after three comparisons without a new best. The failed source and reports are preserved privately.
