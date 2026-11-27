# 0x38f9c0 BGSEquipSlot::sub_140331580

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0x38f9c0 BGSEquipSlot::sub_140331580
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 103/103
- Attempts: 5

## What differed

Early returns on null or self-match followed by a `for` loop with `if (found) break;` duplicated epilogues and caused MSVC to strength-reduce the array index into an extra scaled byte offset register. Rewriting as `while (!found && i < count)` matched the exact 103-byte unrotated loop layout, and matched.

## Spellings tried that did not help

- Early `if (!a_other) return false;` plus `for (i = 0; i < count; ++i) { ... if (found) break; }`: 153/103 B (duplicated epilogue and extra callee-saved register for pointer stride).
- `for (i = 0; i < count && !found; ++i)`: 126/103 B (rotated loop with `!found` checked at top and `i < count` at bottom).
- `while (i < count) { ... ++i; if (found) break; }`: 111/103 B (inverted test order).

## Spelling that fixed it

Guard the whole body with `if (a_other)` so the null path shares the single `return found;` epilogue, loop with `while (!found && i < count)`, and index through `parentSlots[i]` (`EquipSlotArray::operator[]`).

```cpp
bool found = false;
if (a_other) {
    if (this == a_other) return true;
    std::uint32_t i = 0;
    const std::uint32_t count = parentSlots.size;
    while (!found && i < count) {
        found = parentSlots[i]->sub_140331580(a_other);
        ++i;
    }
}
return found;
```
