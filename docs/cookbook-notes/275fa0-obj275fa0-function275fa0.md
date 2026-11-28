# 0x275fa0 Obj275fa0::Function275fa0

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0x275fa0 Obj275fa0::Function275fa0
- Label: none
- Outcome: fixed
- Cause: register-allocation
- Best score: 167/167 (aligned_matching_bytes)
- Attempts: 4

## What differed

The candidate matched the exact size and all control flow of this reverse-order recursive scene-graph search, except that the compiler loaded the child array base pointer into the first argument register instead of the scratch return register before indexing the child slot.

## Spellings tried that did not help

- `while (i != 0u) { --i; ... node->children[i] ... }` with a raw pointer array.
- Signed reverse loop `for (std::int32_t i = static_cast<std::int32_t>(node->childCount) - 1; i >= 0; --i)`.
- Wrapping the child entry in a single-pointer struct with a separate `--i` statement in the `while` loop.

## Spelling that fixed it

Pre-decrementing the unsigned index directly inside the subscript expression and binding the child pointer to a local before the recursive call selected the matching scratch register for the array base:

```cpp
for (std::uint32_t i = node->childCount; i > 0u; ) {
    SceneObj275fa0* child = node->children[--i].ptr;
    SceneObj275fa0* found = Function275fa0(child, a_name);
    if (found) {
        return found;
    }
}
```
