# 0x93e430 Inventory3DManager::GetModelScale

<!-- tags: wall/register-schedule, construct/float -->

- Function: 0x93e430 Inventory3DManager::GetModelScale
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 45/64 aligned matching bytes; distance 2; candidate size 59 versus target 64
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The candidate loads the model count into a register for its initial test and retains it for indexing. The target tests the member in memory and reads it again after selecting the small-array storage. The different count lifetime changes the decrement and function extent. Both choose the last loaded model's local scale or a unit fallback.

## Spellings tried that did not help
A combined guard and two separate early guards both measured 45/64. Initializing one scalar result and assigning it in the model branch measured 36/64 with a 58-byte candidate. A single-job bounded permutation search tested 225 candidates and kept distance 2 with no zero-distance winner.

## Spelling that fixed it
None. The final source restores the original combined guard, reproduces the best score and stops after three comparisons without a new best. The failed source, attempted spellings and reports remain private.
