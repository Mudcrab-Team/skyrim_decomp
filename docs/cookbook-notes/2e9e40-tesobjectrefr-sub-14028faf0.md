# 0x2e9e40 TESObjectREFR::sub_14028FAF0

<!-- tags: wall/control-flow, wall/register-schedule -->

- Function: 0x2e9e40 TESObjectREFR::sub_14028FAF0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 118/144 (aligned_matching_bytes)
- Attempts: 4

## What differed

The candidate reproduced forty-five instructions and the three-epilogue structure, but constant-propagated the false return value to a zeroing instruction on the early-exit path instead of keeping the false local live and copying it on exit, and allocated a different scratch register for the actor downcast and marker virtual dispatch.

## Spellings tried that did not help

- Returning the initialized `bool result = false` local on both the actor-cast and marker early exits.
- Nesting the actor-cast, marker, and weight checks under `if (!As<Actor>())` with a single trailing `return result;`.
- Combining the actor-cast and marker checks into one `if` statement with `return result;` inside and outside.
- Returning `true` directly from the weight check instead of assigning `result = true`.

## Spelling that fixed it

none
