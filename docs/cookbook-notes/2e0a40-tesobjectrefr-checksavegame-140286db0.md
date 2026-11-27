# 0x2e0a40 TESObjectREFR::CheckSaveGame_140286DB0

<!-- tags: wall/register-schedule, wall/flag-fold, construct/bitfield -->

- Function: 0x2e0a40 TESObjectREFR::CheckSaveGame_140286DB0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 89/190 (aligned_matching_bytes)
- Attempts: 4

## What differed

Using a shift-and-mask helper reproduced the shift tests on the save-buffer change flags and save-load manager flags, but the candidate swapped the two callee-saved registers holding the reference pointer and buffer pointer, shifted their stack save slots by eight bytes, and lowered the high-bit test on the in-game form flags to a signed byte comparison instead of a zero-extended byte shift.

## Spellings tried that did not help

- Testing all three flag bits with inline shift-and-mask expressions on integer members.
- Modeling the save-buffer flags and save-load manager flags as C++ bitfield structs.
- Using an inline `TestBit` helper for the two thirty-two-bit flag tests and `TestBit8` for the eight-bit flag test.
- Modeling the in-game form flag byte as a one-bit unsigned bitfield and inverting the virtual-dispatch branch order.

## Spelling that fixed it

none
