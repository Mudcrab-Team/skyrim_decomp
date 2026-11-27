# 0x416240 Sky::UpdateLightLODFadeDistances

<!-- tags: method/diagnostic -->

- Function: 0x416240 Sky::UpdateLightLODFadeDistances
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 542/584 (aligned_matching_bytes)
- Attempts: 4

## What differed

Candidate reached the exact `584`-byte size (`542` aligned bytes), differing only in which general-purpose register MSVC chose when reloading `g_tes` after calling `Function2bc540` in the three `interiorCell` branches.

## Spellings tried that did not help

- Accessing `g_tes->interiorCell` directly vs through an inline `TES::GetSingleton()` helper produced the same second-reload register choice.

## Spelling that fixed it

none
