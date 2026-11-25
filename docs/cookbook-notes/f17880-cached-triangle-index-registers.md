# 0xf17880 NiTriShapeData::Functionf17880

<!-- tags: wall/register-schedule, method/diagnostic -->

- Function: 0xf17880 NiTriShapeData::Functionf17880
- Label: CRASHLOGGER_PDB(59818@2026.10.24), GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 23/50 matching bytes; alignment distance 2; 13 target and 13 candidate instructions
- Attempts: 5

## What differed
The initial original draft reloaded the triangle table after output stores. Caching the table and advancing an unsigned index for the three outputs removed the extra work. The remaining classified differences are four register-renaming edits with alignment distance 2, with all reference inputs resolved and no aligned value differences reported. The final reference-output, const-qualified spelling retains that score. Layout and class naming come from the labelled community-generated PDB table; the method name remains a guess. No sibling middleware bodies were inspected or adapted.

## Spellings tried that did not help
A one-worker native permutation search tested 79 candidates and stopped on patience at distance 2. Naming all three index positions separately worsened the distance to 3; indexing from a shared base with separate additions worsened it to 4. Reference outputs and const qualification returned the score to 2. Comparisons three through five did not improve the best result, triggering the assigned stop rule.

## Spelling that fixed it
None. The retained draft caches the triangle table and advances the index sequentially. This is a local near miss, with no acceptance claim.
