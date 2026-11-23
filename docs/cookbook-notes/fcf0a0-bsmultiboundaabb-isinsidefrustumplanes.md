# 0xfcf0a0 BSMultiBoundAABB::IsInsideFrustumPlanes

- Function: 0xfcf0a0 BSMultiBoundAABB::IsInsideFrustumPlanes
- Label: GUESS(low)
- Outcome: fixed
- Cause: operand-order
- Best score: 163/163
- Attempts: 13

## What differed

The active-plane cursor gave the loop counter and bit mask the target's register assignments. After the projection arithmetic and exits matched, the only remaining difference was the operand order of the bit test.

## Spellings tried that did not help

A count returned from the loop fixed the counter register but changed the exits. Separate scalar projection products changed the extent operand order. In the cursor, swapping the arguments to the bitwise expression kept the same test.

## Spelling that fixed it

Take the mask from the plane set at the call site inside the loop. In the cursor predicate, copy the current bit into a local and intersect that local with the mask. Those two changes were compared together.

```cpp
bool IsActive(std::uint32_t active) const
{
    std::uint32_t selected = bit;
    selected &= active;
    return selected != 0;
}
```
