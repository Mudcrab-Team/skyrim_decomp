# 0x1052030 NiAVObject::FindCollisionObjectRecursive

<!-- tags: wall/control-flow, wall/register-schedule, construct/loop -->

- Function: 0x1052030 NiAVObject::FindCollisionObjectRecursive
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 106/132 matching bytes; candidate extent 131 bytes
- Attempts: 6

## What differed
The best retained draft uses the original object after an AsNode type check, skips null children, and holds a collision result in the loop condition. It differs in the placement and lifetime of zero results and the return paths. The comparator reports a size mismatch for that draft. Alignment reports no behavioral mismatches, which is diagnostic and does not establish equivalence.

## Spellings tried that did not help
Immediate returns from recursive child searches measured 25/132 matching bytes. Adding a null-child guard measured 28/132. A saved result and original-object child access measured 30/132; nesting the outer null case measured 106/132. Separating the root collision pointer from the traversal result then measured 36/132. Moving the traversal result around the successful-node scope did not close it; the sixth comparison failed unwind coverage and measured 45/132. A bounded one-worker search examined 81 candidates without improving its starting distance. Every draft and result is retained privately.

## Spelling that fixed it
none. Stop at the six-comparison limit. The best fourth draft is restored exactly. A future attempt should investigate result initialization and null-return scope together with unwind layout, rather than changing the known child layout. The unit is original from local observations with labelled community declarations and naming facts; no sibling body was read. This is an unaccepted near miss.
