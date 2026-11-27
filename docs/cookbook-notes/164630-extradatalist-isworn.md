# 0x164630 ExtraDataList::IsWorn

<!-- tags: wall/control-flow, wall/inlining, abi/exception -->

- Function: 0x164630 ExtraDataList::IsWorn
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 249/265 (aligned_matching_bytes)
- Attempts: 6

## What differed

Inlining the four read-locked presence-bit checks reproduced the prologue, the lock-guard instructions, and the bit shifts across all four branches, but the compiler either duplicated the `return true` epilogue or merged the trailing branches into `setne` instead of sharing one `return false` epilogue after the first branch and one `return true` epilogue at the end.

## Spellings tried that did not help

- Calling a non-template `HasType(std::uint32_t)` helper (not inlined due to the exception-handling lock guard).
- Expanding all four `BSReadLockGuard` presence checks inline with early `return wornLeft` / `return wornRight`.
- Returning `true` / `false` explicitly from each branch with a shared `bool found` variable.
- Moving the single `return false` to the bottom of the function.
- Inverting each check to `if (!found) return false;` with a single `return true` at the bottom.
- Using a `template <std::uint32_t Shift> bool HasWornBit()` helper (still not inlined due to the lock guard).

## Spelling that fixed it

none
