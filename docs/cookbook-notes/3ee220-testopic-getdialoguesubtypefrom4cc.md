# 0x3ee220 TESTopic::GetDialogueSubtypeFrom4CC

- Function: 0x3ee220 TESTopic::GetDialogueSubtypeFrom4CC
- Label: SYMBOLS(tesv-2013-map) SYMBOLS(fo4-pdb)
- Outcome: fixed
- Cause: register-allocation
- Best score: 48/48
- Attempts: 8

## What differed

The loop selects between the current index and the previous result in a
separate temporary. An inline conditional expression updated the result
in place, omitting a copy and changing the loop tail.

## Spellings tried that did not help

A separate match-index local in the loop still updated the result in place.
A helper that advanced the index by reference and a cursor struct changed
the register assignments. With the selection helper in place, a wider
index changed the loop to maintain a running byte offset.

## Spelling that fixed it

Use a bounded table cursor with a 32-bit index and pass the row, key, index
and previous result to a helper that only selects the result. The caller
advances the index and checks the result sentinel.

```cpp
static inline std::uint32_t MatchIndex(const TopicTypeEntry& row, std::uint32_t fourCC,
                                       std::uint32_t index, std::uint32_t previous)
{
    return row.type != fourCC ? previous : index;
}
```
