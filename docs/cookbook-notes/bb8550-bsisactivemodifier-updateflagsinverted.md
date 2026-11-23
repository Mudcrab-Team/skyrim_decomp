# 0xbb8550 BSIsActiveModifier::UpdateFlagsInverted

- Function: 0xbb8550 BSIsActiveModifier::UpdateFlagsInverted
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 51/51
- Attempts: 10

## What differed

The compiler moved each next flag comparison ahead of the preceding flag store. The matching version kept each pair's update together.

## Spellings tried that did not help

Direct assignments and conditional assignments with a volatile destination did not preserve the order. Making the input volatile added extra loads. An eight-bit bit-field destination also left the comparison reordered.

## Spelling that fixed it

A non-volatile pair with a small inline member called once for each pair matched:

```cpp
struct Pair {
    bool active;
    unsigned char disabled;
    void Refresh() { active = !disabled; }
};
```
