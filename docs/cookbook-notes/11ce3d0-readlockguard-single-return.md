# 0x11ce3d0 MovementAgentPathFollowerStandard::Function11ce3d0

<!-- tags: wall/control-flow, wall/layout -->

- Function: 0x11ce3d0 MovementAgentPathFollowerStandard::Function11ce3d0
- Label: GUESS
- Outcome: fixed
- Cause: branch-layout
- Best score: 151/151 (aligned_matching_bytes)
- Attempts: 4

## What differed

Holding a `BSReadLockGuard` across early `return` statements split the EH unwind metadata (`eh-data-mismatch`) even when the generated instructions matched. Converting the function to initialize `bool result = false;` before the branch fixed the EH table, but kept `result` live across all conditions and forced the compiler to save one more register. Returning a single boolean expression directly let the compiler reuse the object pointer register for the result after the final check and matched both the code bytes and the EH metadata.

## Spellings tried that did not help

- Two early `return true;` statements and a trailing `return false;` under `BSReadLockGuard`: matched code shape closely, but failed with `eh-data-mismatch`.
- `bool result = false;` followed by `if (...) result = true; else if (...) result = true; return result;`: fixed EH metadata, but saved one more register, so the candidate grew past 151 bytes.

## Spelling that fixed it

```cpp
BSReadLockGuard guard(unkE8);
return unkF0 == 0 || unkF0 == 12 ||
       (unkF0 == 10 && unkF8 && unk100 && unkF8->unk90 > 0.0f && unk100->unk8C == unk100->unk80 - 1);
```
