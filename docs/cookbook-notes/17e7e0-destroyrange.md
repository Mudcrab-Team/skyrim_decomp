# 0x17e7e0 Func_17e7e0::DestroyRange

<!-- tags: method/diagnostic -->

- Function: 0x17e7e0 Func_17e7e0::DestroyRange
- Label: GUESS(low)
- Outcome: fixed
- Cause: loop-shape
- Best score: 91/91 (aligned_matching_bytes)
- Attempts: 5

## What differed

Indexing `data[startIndex + i]` inside a range-destructor loop kept the base array pointer live inside the loop body and reloaded or recomputed element addresses across the virtual release call. Advancing an explicit end-pointer loop also changed loop-exit comparison shape and register saves.

## Spellings tried that did not help

- Indexed `for (std::uint32_t i = 0; i < count; ++i)` calling `data[startIndex + i].~Entry()`.
- Indexed loop starting at `startIndex` up to `startIndex + count`.
- Pointer loop comparing `cur != end` computed from `data + startIndex + count`.
- Computing `cur = &data[startIndex]` inside an `if (count != 0)` guard.

## Spelling that fixed it

Load the array base pointer into a local variable before the loop, take the address of element `startIndex`, and advance `cur` across a `count`-bounded `for` loop:

```cpp
Entry* base = data;
Entry* cur = &base[startIndex];
for (std::uint32_t i = 0; i < count; ++i)
{
    cur->~Entry();
    ++cur;
}
```
