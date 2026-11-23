# 0x2f0b70 TESObjectREFR::GetReferencePositionInSpace

- Function: 0x2f0b70 TESObjectREFR::GetReferencePositionInSpace
- Label: GUESS(low)
- Outcome: fixed
- Cause: inlining
- Best score: 126/126
- Attempts: 10

## What differed

The target has two conditional selections for the parent cell, one on each side of the interior check. Both keep the candidate world pointer in the result location and replace it with the cell only when it is null. Several drafts merged the selections or allocated the cell to the result location.

## Spellings tried that did not help

An inline conditional in the outer position builder, an output constructor, and an explicit output reference alone all missed. Putting the selection inside a cell member got the pointer roles right but still collapsed the null branch.

## Spelling that fixed it

Pass the conditional exterior-world value as the first argument to a small selection helper from the cell member. Keep the cell as the fallback argument. The position builder calls the cell member and writes its result after the position components.

```cpp
TESForm* SelectSpace(TESForm* world, TESForm* cell)
{
    return world == nullptr ? cell : world;
}

TESForm* Cell::GetCellSpace()
{
    return SelectSpace(IsInteriorCell() ? nullptr : worldSpace, this);
}
```
