# 0x2036e0 BSCullingProcess::AppendNonAccum

<!-- tags: construct/destructor, abi/exception, method/binding -->

- Function: 0x2036e0 BSCullingProcess::AppendNonAccum
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 106/106 aligned bytes
- Attempts: 4

## What differed

The temporary allocator needs an unwind destructor even though normal execution proceeds directly from the append call to testing the returned index. The same cleanup appears in the other AppendNonAccum entry and in ReserveObjectArray.

## Spellings tried that did not help

An out-of-line destructor added a normal-path call and extended the lifetime of the returned index across it. Defaulting the base destructor removed the unwind cleanup.

## Spelling that fixed it

Give the allocator interface and its concrete local functor inline, user-provided empty virtual destructors. Create the functor inside the array operation. The compiler inlines destruction on return and emits a cleanup funclet. The sole destructor reference in each private pack identifies the binding for that funclet.
