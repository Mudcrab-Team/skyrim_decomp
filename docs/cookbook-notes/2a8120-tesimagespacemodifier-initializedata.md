# 0x2a8120 TESImageSpaceModifier::InitializeData

<!-- tags: method/diagnostic -->

- Function: 0x2a8120 TESImageSpaceModifier::InitializeData
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 68/68
- Attempts: 5

## What differed

After a call that zeroes a block the target still stores zero to a word in that block. The candidate dropped the store as dead after the memset, so it was 9 bytes shorter. A volatile word store kept it but used a zeroed register instead of the immediate word store.

## Spellings tried that did not help

A volatile 16-bit member (register store, size matched but bytes differ). An explicit zero store after a direct `std::memset` in the owner (store removed). An opaque external zeroing function matched, but the review refused it as a helper declared only to keep redundant stores.

## Spelling that fixed it

Zero the block through an inline method of the data structure that calls `std::memset(this, 0, sizeof(*this))`, then assign the two-float point as one structure value before the two byte members. The point assignment is what keeps the later zero stores; assigning its two floats one by one drops them.

```cpp
data.Clear();
data.duration = 1.0f;
data.radialBlurCenter = NiPoint2{ 0.5f, 0.5f };
data.dof.useTarget = false;
data.dof.flags = 0;
```
