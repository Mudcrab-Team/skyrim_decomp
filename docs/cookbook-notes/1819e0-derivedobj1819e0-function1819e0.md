# 0x1819e0 DerivedObj1819e0::Function1819e0

<!-- tags: method/diagnostic -->

- Function: 0x1819e0 DerivedObj1819e0::Function1819e0
- Label: GUESS(low)
- Outcome: fixed
- Cause: struct-layout
- Best score: 44/44 (aligned_matching_bytes)
- Attempts: 4

## What differed

Initializing the trailing handle field directly with an integer literal in the constructor initializer list folded the store with adjacent zero initializations instead of emitting a separate default-initialized member store at the end of the constructor.

## Spellings tried that did not help

- Storing the global invalid-handle constant directly into a plain integer member in the constructor body.
- Assigning the handle member in the constructor initializer list as a raw unsigned integer field.

## Spelling that fixed it

Wrap the handle value in a small member struct whose default constructor reads the global invalid-handle constant, and let the enclosing class constructor initialize that member after the base class and earlier fields:

```cpp
struct RefHandle
{
    RefHandle()
        : value(g_invalidHandle)
    {
    }

    std::uint32_t value;
};
```
