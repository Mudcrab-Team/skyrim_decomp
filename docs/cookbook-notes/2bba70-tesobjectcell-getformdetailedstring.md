# 0x2bba70 TESObjectCELL::GetFormDetailedString

<!-- tags: wall/control-flow, wall/register-schedule -->

- Function: 0x2bba70 TESObjectCELL::GetFormDetailedString
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 109/381 (aligned_matching_bytes)
- Attempts: 2

## What differed

In both exterior formatting branches, the target evaluates the exterior-data null check separately for the Y and X coordinates and reads the form ID and form flags before calling the virtual editor-ID getter. The candidate reused one null check for both coordinates and deferred reading the form fields until after the virtual calls, which changed the callee-saved register set and frame size.

## Spellings tried that did not help

- Computing `cellX` and `cellY` locals before calling the variadic formatter.
- Passing inline `GetCellGridX` and `GetCellGridY` helper calls directly as variadic arguments.

## Spelling that fixed it

none
