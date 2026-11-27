# 0x2a4100 TESImageSpaceModifier::ApplyCrossFade

<!-- tags: method/diagnostic -->

- Function: 0x2a4100 TESImageSpaceModifier::ApplyCrossFade
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: other
- Best score: 326/360 (aligned_matching_bytes)
- Attempts: 6

## What differed

When a named smart-pointer local is passed into the inlined list removal helper inside the active-crossfade guard, every branch in the body matches the target layout, including the null checks inside the removal helper and the smart-pointer destructor. However, the compiler reloads the smart-pointer stack slot three extra times after the atomic reference-count updates instead of reusing the pointer register across those updates, adding twelve bytes. Passing a temporary smart pointer directly omits those reloads at entry, but folds away both inner null checks and still reloads the stack slot inside the search loop and destructor.

## Spellings tried that did not help

- Implicit temporary smart pointer passed directly to `Remove(const T&)` (357 B; drops both inner null checks and reloads the stack slot inside the loop and destructor).
- Passing the smart pointer by value to `Remove(T)` (419 B; duplicates the destructor at every early return and adds a second stack slot).
- Default-constructing the smart-pointer local and assigning through `operator=(T*)` (381 B; adds zero initialization before the assignment).
- Named local smart pointer constructed from the active pointer, with or without `volatile` on the reference count and with either `Remove(const T&)` or `Remove(T*)` (372 B, 326/360 aligned; matches every branch but emits three extra stack-slot reloads after the atomic updates).
- Omitting the outer active-crossfade null check and calling `Remove` unconditionally (368 B; moves the null check after the stack store and still reloads after the atomic updates).

## Spelling that fixed it

none
