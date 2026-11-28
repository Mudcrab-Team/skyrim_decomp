# 0x13bda0 Func_13bda0::ConstructMove

<!-- tags: method/diagnostic -->

- Function: 0x13bda0 Func_13bda0::ConstructMove
- Label: GUESS(low)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 160/166 (aligned_matching_bytes)
- Attempts: 6

## What differed

Placement move-constructing a struct that holds two 16-byte subobjects (each one 32-bit integer followed by three floats) lowered plain aggregate float copies to scalar integer or 64-bit vector moves instead of three separate single-precision float loads and stores.

## Spellings tried that did not help

- Defaulted move constructor over plain `std::uint32_t` and `float` fields (short, combined 64-bit moves).
- User-defined copy constructor on a 3-float subobject copying `x`, `y`, `z` directly (still lowered as integer copies).
- Forwarding `x`, `y`, `z` through a 3-float setter helper or 3-float delegating constructor (kept the first float in an integer register).
- Switching the unit to `o2-fpfast.json` (unchanged).

## Spelling that fixed it

Still unsolved; grouping the 32-bit integer and three floats into one 4-field subobject with a 4-argument delegating copy constructor matched the 166-byte size and reached 160/166 aligned bytes:

```cpp
struct Pose
{
    Pose(std::uint32_t t, float px, float py, float pz) : tag(t), x(px), y(py), z(pz) {}
    Pose(const Pose& o) : Pose(o.tag, o.x, o.y, o.z) {}
    std::uint32_t tag;
    float x, y, z;
};
```
