# 0x101bbe0 NiObjectTargetFinder101bbe0::FindControllerManagerTarget

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x101bbe0 NiObjectTargetFinder101bbe0::FindControllerManagerTarget
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 166/166 (aligned_matching_bytes)
- Attempts: 5

## What differed

The compiler placed the shared `target` return block in the middle of the function, checked the controller pointer before the virtual `AsNode()` result, or emitted a redundant null test before dereferencing the found controller at the shared tail return.

## Spellings tried that did not help

- Returning `ctrl->target` directly inside both the `AsNode()` branch and the linked-list loop caused the compiler to place the return block between the two branches instead of at the end.
- Loading `controllers` before checking `AsNode()` swapped the order of the two null checks.
- Setting `found` and returning `found ? found->target : nullptr` kept the return block at the end but added a redundant null check before dereferencing `found`.

## Spelling that fixed it

Return `nullptr` explicitly in both failure paths, assign `found` on both success paths, and dereference `found->target` once at the end of the function (short form):

```cpp
if (AsNode()) {
    if (!controllers || !controllers->IsKindOf(rtti)) return nullptr;
    found = controllers;
} else {
    for (auto* ctrl = controllers; ctrl; ctrl = ctrl->next) {
        if (ctrl->IsKindOf(rtti)) { found = ctrl; break; }
    }
    if (!found) return nullptr;
}
return found->target;
```
