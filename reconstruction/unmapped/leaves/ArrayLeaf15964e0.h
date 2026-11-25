// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf15964e0, ArrayLeaf15964e0Storage, ArrayLeaf15964e0Size, FreeArrayLeaf15964e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf15964e0Storage
{
    ~ArrayLeaf15964e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf15964e0Size
{
    ~ArrayLeaf15964e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf15964e0 : public ArrayLeaf15964e0Storage, public ArrayLeaf15964e0Size
{
    ~ArrayLeaf15964e0();  // compared: 0x15964e0
};

void FreeArrayLeaf15964e0(ArrayLeaf15964e0* array);
