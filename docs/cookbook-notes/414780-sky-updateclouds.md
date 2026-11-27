# 0x414780 Sky::UpdateClouds

<!-- tags: method/diagnostic -->

- Function: 0x414780 Sky::UpdateClouds
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 713/884 (aligned_matching_bytes)
- Attempts: 6

## What differed

Separating `NiPointer(T*)` construction order from `~NiPointer()` and inlining `NiPointer::operator=` aligned the reference-counted updates (`713` aligned bytes), while boolean temporary evaluation (`sameTex`), float clamping, and `~NiPointer` exception-handling placement left an `8`- to `10`-byte length gap.

## Spellings tried that did not help

- Assigning `_ptr` before vs after `IncRefCount` in `NiPointer` constructor.
- Using `ratio < 0.0f` vs `!(ratio >= 0.0f)` for cloud alpha clamping.
- Combining `sameTex` with logical AND vs nested `if` blocks.

## Spelling that fixed it

none
