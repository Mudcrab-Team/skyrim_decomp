# 0x11ecb00 BSCompressedNavmeshBounds::BSCompressedNavmeshBounds

<!-- tags: construct/constructor, wall/register-schedule -->

- Function: 0x11ecb00 BSCompressedNavmeshBounds::BSCompressedNavmeshBounds
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 95/95 (aligned_matching_bytes)
- Attempts: 4

## What differed

Default trivial struct copy of two three-float point members emitted wide 64-bit moves instead of six scalar float loads and stores. Assigning the six scalar floats in the constructor body matched the instruction count, but the compiler scheduled the final float store after the trailing zero stores and return-value copy.

## Spellings tried that did not help

- Aggregate member initialization of two trivial three-float structs from a global point.
- Zeroing trailing integer fields in the member initializer list while copying float components in the constructor body.
- Assigning all six float components and then the trailing integer fields sequentially in the constructor body.

## Spelling that fixed it

Give the three-float point struct an explicit inline copy constructor that initializes each float field individually, and initialize all members in declaration order in the constructor initializer list:

```cpp
struct NiPoint3 {
    NiPoint3() {}
    NiPoint3(const NiPoint3& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}
    float x, y, z;
};
BSCompressedNavmeshBounds::BSCompressedNavmeshBounds()
    : minBound(gZeroPoint3), maxBound(gZeroPoint3), unk18(0), unk20(0), unk28(0) {}
```
