# 0xff7430 BSCompoundFrustum::ReleaseToPool

<!-- tags: construct/allocation, wall/layout -->

- Function: 0xff7430 BSCompoundFrustum::ReleaseToPool
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 170/170 aligned matching bytes
- Attempts: 5 comparisons, first local pass on comparison 1

## What differed

Returning an entry needs a byte-range membership check before deriving an index. An address outside the fixed array follows the destructor and sized-delete path.

## Spellings tried that did not help

The first byte-range implementation passed. Sharing the guard and class layout with the allocation method retained the result.

## Spelling that fixed it

Subtract the pool base as an unsigned integer address and compare the byte distance with the extent of the entire array. Divide that distance by the object size only in the in-range branch.
