// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6ba2f0, ArrayLeaf6ba2f0Storage, ArrayLeaf6ba2f0Size, FreeArrayLeaf6ba2f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6ba2f0Storage
{
    ~ArrayLeaf6ba2f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6ba2f0Size
{
    ~ArrayLeaf6ba2f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6ba2f0 : public ArrayLeaf6ba2f0Storage, public ArrayLeaf6ba2f0Size
{
    ~ArrayLeaf6ba2f0();  // compared: 0x6ba2f0
};

void FreeArrayLeaf6ba2f0(ArrayLeaf6ba2f0* array);
