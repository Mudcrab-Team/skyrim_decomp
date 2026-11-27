# 0x2bf880 TESObjectCELL::sub_1402662B0

<!-- tags: wall/control-flow, wall/register-schedule -->

- Function: 0x2bf880 TESObjectCELL::sub_1402662B0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 78/138 (aligned_matching_bytes)
- Attempts: 5

## What differed

The target initializes a local boolean to false in a callee-saved register, returns true immediately if the worldspace disables grass, and then checks the exterior land flag bit using a conditional move against that saved false register with two separate epilogues. Candidates either merged the final epilogues into one or folded the false variable away into a flag-set instruction.

## Spellings tried that did not help

- Single `bool result = false` updated inside the exterior land check and returned once at the end.
- Returning directly inside the exterior land check (`return true` / `return result`), which let the compiler fold the local to constant false.
- Storing the worldspace call result into the boolean local before checking it.

## Spelling that fixed it

none
