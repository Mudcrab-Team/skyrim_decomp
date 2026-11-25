# 0x155dc00 BSTArray<ShadowmapDescriptor>::SetSize

<!-- tags: wall/inlining, construct/loop, construct/destructor, abi/exception -->

- Function: 0x155dc00 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::SetSize (also 0x155d970 Clear)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 281/281 from 166/281
- Attempts: 6

## What differed
The target resizes with the destroy loop written out inside the zero-size branch, calls the shared out-of-line item destructor
only when shrinking to a non-zero size, and keeps `Clear` as its own function that the array destructor calls. The draft called
`Clear(false)` from `SetSize`, so the loop was missing from `SetSize` and 115 bytes were absent.

## Spellings tried that did not help
- Reordering the explicit instantiations, in-class versus out-of-class `Clear`.
- `Clear` calling the item destructor helper: it either inlined everywhere or nowhere.

## Spelling that fixed it
`SetSize` destroys the items itself in the zero branch (cached count, pointer walk); `Clear` has its own loop and is marked
`noinline` (the destructor calls it out of line), and the shrink path keeps `DestructItems` out of line. Without the `noinline`
on `Clear` the destructor started inlining it once `SetSize` stopped calling it.
