// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6d03e0, ArrayLeaf6d03e0Storage, ArrayLeaf6d03e0Size, FreeArrayLeaf6d03e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6d03e0Storage
{
    ~ArrayLeaf6d03e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6d03e0Size
{
    ~ArrayLeaf6d03e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6d03e0 : public ArrayLeaf6d03e0Storage, public ArrayLeaf6d03e0Size
{
    ~ArrayLeaf6d03e0();  // compared: 0x6d03e0
};

void FreeArrayLeaf6d03e0(ArrayLeaf6d03e0* array);
