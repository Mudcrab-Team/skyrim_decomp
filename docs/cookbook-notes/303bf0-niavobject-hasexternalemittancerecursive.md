# 0x303bf0 NiAVObject::HasExternalEmittanceRecursive

<!-- tags: wall/register-schedule, wall/control-flow, construct/bitfield -->

- Function: 0x303bf0 NiAVObject::HasExternalEmittanceRecursive
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 97/196 (aligned_matching_bytes)
- Attempts: 6

## What differed

The target shrink-wraps three callee-saved register saves inside the node branch and performs a sixty-four-bit bitmask test after a thirty-two-bit read of the shader-property flags, whereas the candidate saved those registers at entry and tested only the low half of the flags word.

## Spellings tried that did not help

- Casting the geometry property through an `IsKindOf` helper and testing a single bit of a `std::uint32_t` flags field.
- Reading the flags field as a `std::uint64_t` bitmask and testing against a shifted mask constant.
- Testing the flags field with a `std::uint32_t` bitfield struct.
- Wrapping the child-array lookup in a `GetChildAt` helper and switching the recursive `BSVisit` loop between `std::uint32_t` and `std::uint16_t` indices.
- Splitting the geometry-check branch and the node-recursion branch into separate inline helpers.
- Moving the early-return flag into a local `result` variable initialized before the null check.

## Spelling that fixed it

none
