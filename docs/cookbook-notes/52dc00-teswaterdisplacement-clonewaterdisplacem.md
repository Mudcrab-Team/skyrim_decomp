# 0x52dc00 TESWaterDisplacement::CloneWaterDisplacementGeometry

<!-- tags: method/diagnostic -->

- Function: 0x52dc00 TESWaterDisplacement::CloneWaterDisplacementGeometry
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 397/472 (aligned_matching_bytes)
- Attempts: 3

## What differed

Candidate compiled to `465` vs `472` bytes (`397` aligned), lacking some stack-slot initialization around `if (unk128)` and the `!prop` check, and with a small difference before the return.

## Spellings tried that did not help

- Replacing the ternary `AsGeometry()` shader-property initializer with an explicit `nullptr` default and `if (cloned->AsGeometry())` check kept `465` bytes.

## Spelling that fixed it

none
