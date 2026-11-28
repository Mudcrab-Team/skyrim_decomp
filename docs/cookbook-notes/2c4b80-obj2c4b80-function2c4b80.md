# 0x2c4b80 Obj2c4b80::Function2c4b80

<!-- tags: construct/bitfield, construct/float, wall/flag-fold, wall/control-flow -->

- Function: 0x2c4b80 Obj2c4b80::Function2c4b80
- Label: none
- Outcome: fixed
- Cause: float-codegen
- Best score: 137/137 (aligned_matching_bytes)
- Attempts: 6

## What differed

Three small code-generation differences appeared across iterations on this exterior cell bounds check:
1. A direct bit test or bitfield on the form flags member folded into a single memory test instead of a load, right shift, and low-bit check.
2. Initializing the fallback cell coordinates before the pointer check moved zeroing above the branch and shifted register assignments.
3. Mutating the truncated float in place inside a floor helper caused the compiler to fold subtraction of one into addition of negative one, whereas returning from each branch bypassed the shared float-to-integer conversion at the end of the floor helper.

## Spellings tried that did not help

- Direct bit shift and mask in the branch condition (`((formFlags >> 13) & 1u) != 0`), which folded into a memory test.
- One-bit bitfield member on the form flags word, which also folded into a memory test.
- In-place decrement (`asFloat -= 1.0f` and `asFloat = asFloat - 1.0f`), which emitted addition of negative one instead of subtraction of positive one.
- Early return before the float-to-integer conversion in the floor helper, which bypassed the final conversion on the non-negative branch.

## Spelling that fixed it

Using a by-value bit-test helper (`TestBit(formFlags, 13u)`), assigning zero coordinates in the explicit `else` branch, and computing the floored float with a ternary before a single integer conversion closed the function:

```cpp
bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

std::int32_t FloorCoord(float a_value)
{
    float asFloat = static_cast<float>(static_cast<std::int32_t>(a_value));
    float floored = (a_value - asFloat >= 0.0f) ? asFloat : (asFloat - 1.0f);
    return static_cast<std::int32_t>(floored);
}
```
