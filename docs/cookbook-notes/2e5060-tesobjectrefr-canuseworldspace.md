# 0x2e5060 TESObjectREFR::CanUseWorldSpace

- Function: 0x2e5060 TESObjectREFR::CanUseWorldSpace
- Label: GUESS(low)
- Outcome: fixed
- Cause: constant-folding
- Best score: 99/99
- Attempts: 6

## What differed

The target snapshots a flag word and checks its two bits in separate branches before testing the world pointer. The candidate combined the flag tests.

## Spellings tried that did not help

Word-sized bit-fields with logical operators merged into one mask. Bitwise OR on two boolean locals kept both bit extractions but merged the branches. Byte-sized bit-fields changed the width of the snapshot.

## Spelling that fixed it

Pass the same unsigned flag snapshot to a helper for each test. Truncate the shifted value to a byte before computing its remainder. The two helper results are used with logical short-circuit evaluation.

```cpp
inline bool IsRecordBitSet(std::uint32_t flags, unsigned bit)
{
    const auto lowBits = static_cast<std::uint8_t>(flags >> bit);
    return lowBits % 2 == 1;
}
```
