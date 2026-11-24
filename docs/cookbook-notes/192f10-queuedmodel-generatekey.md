# 0x192f10 QueuedModel::GenerateKey

<!-- tags: method/diagnostic, method/sibling, sibling/fo4, wall/constant, wall/layout -->

- Function: 0x192f10 QueuedModel::GenerateKey
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: exact
- Attempts: 6

## What differed

A task key is rebuilt from two shared counters (locked increments) and one byte of the old key. The
function has the same statements as a sibling body, but different bit positions. With unsigned 64-bit
arithmetic the compiler folded the whole expression into two plain shifts and one large constant: the
target instead adds a constant to the offset, shifts by one amount, adds the byte, shifts again and adds
the counter, in that order, and widens the 16-bit counter right after the increment.

## Spellings tried that did not help

- The flat form `(offset << 24) + (middle << 16) + constant + counter` on unsigned 64-bit values.
- The nested form with the same shifts and adds written in the target's order on unsigned values: identical
  code to the flat form, the compiler reassociates unsigned sums and shifts.
- The same steps as separate statements on a local `unsigned __int64`: identical code again.

## Spelling that fixed it

The key member is a signed 64-bit integer (the target shifts it with an arithmetic shift). Doing the
arithmetic on `std::int64_t` stops the reassociation and keeps the target's order of operations; and
declaring the counter local as `std::int64_t` (initialised from the `unsigned short` cast) moves its
zero-extension to just after the increment, as the target has it.

```cpp
const std::int64_t counter = static_cast<unsigned short>(_InterlockedIncrement(&iStaticCounter));
const auto middle = static_cast<unsigned char>(iKey >> 16);
const auto offset = static_cast<unsigned int>(_InterlockedIncrement(&iStaticOffset));
iKey = ((((static_cast<std::int64_t>(offset) + 0x100000000LL) << 8) + middle) << 16) + counter;
```
