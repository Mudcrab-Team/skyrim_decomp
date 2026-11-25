# 0xfa18c0 NiPSysMeshUpdateModifier::RegisterStreamables

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xfa18c0 NiPSysMeshUpdateModifier::RegisterStreamables
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: comparator PASS; previous 94/102 matching bytes, alignment distance 1
- Attempts: 3

## What differed
The mesh-array size field is 16-bit, but the loop's index arithmetic in the target uses a wider type. Matching the stored size's width in the loop variable produced extra narrowing work. Widening the index to 64 bits removed that work but left two operand-width differences.

## Spellings tried that did not help
A 16-bit index matched 86/102 bytes at alignment distance 6. A 64-bit index improved to 94/102 bytes at distance 1. Both comparisons failed. The same null-element check, repeated size read and ignored per-element registration result were retained.

## Spelling that fixed it
Use a 32-bit unsigned loop index while retaining the array's 16-bit size declaration. The third comparison passed with the default recipe. The index width follows the observed arithmetic rather than the container's size storage width. No sibling implementation body was read or adapted; local PASS remains candidate evidence pending independent acceptance.
