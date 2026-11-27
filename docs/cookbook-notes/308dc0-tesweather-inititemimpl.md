# 0x308dc0 TESWeather::InitItemImpl

<!-- tags: method/diagnostic -->

- Function: 0x308dc0 TESWeather::InitItemImpl
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 680/1124 (aligned_matching_bytes)
- Attempts: 6

## What differed

Sharing one `std::uint32_t id` across single-pointer resolutions aligned stack slots (`680` of `1124` bytes), while the `skyStatics` resolution loop was strength-reduced to an index counter instead of keeping pointer iteration (`it != end`), leaving a `12`-byte size difference (`1112` vs `1124`).

## Spellings tried that did not help

- Index-based `for` loops and pointer-based `for` / `do-while` loops over `skyStatics` both lowered differently from the target pointer comparison.

## Spelling that fixed it

none
