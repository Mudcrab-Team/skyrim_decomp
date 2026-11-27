# 0x6d66f0 Actor::CheckCast_140631CE0

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x6d66f0 Actor::CheckCast_140631CE0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 133/133 (aligned_matching_bytes)
- Attempts: 4

## What differed

The target initializes both a false result flag and a true loop-continuation flag, tests the continuation flag at the top of the loop, updates it from the negated result at the end of every iteration (including when the caster slot is null), and checks the four-slot bound at the bottom of the loop. Direct negation of the result in the loop condition merged the two flags and dropped the continuation register, while placing the continuation flag before the bound moved the bound test to the top of the loop.

## Spellings tried that did not help

- `for (std::uint32_t i = 0; i < 4 && !result; ++i)` without a separate continuation boolean: dropped the continuation flag and swapped the index and pointer registers.
- `for (std::uint32_t i = 0; cont && i < 4; ++i)` with `cont = !result` inside the null check: placed the index bound check at the top of the loop and expanded the body.
- `for (std::uint32_t i = 0; i < 4 && cont; ++i)` with `cont = !result` inside the null check: matched the size and registers, but the null branch skipped the `cont = !result` update.

## Spelling that fixed it

```cpp
bool result = false;
bool cont   = true;
for (std::uint32_t i = 0; i < 4 && cont; ++i) {
    if (magicCasters[i]) {
        result = magicCasters[i]->CheckCast(a_spell, a_dualCast, nullptr, a_reason, false);
    }
    cont = !result;
}
return result;
```
