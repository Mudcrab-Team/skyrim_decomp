// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf109e0f0, ArrayLeaf109e0f0Storage, ArrayLeaf109e0f0Size, FreeArrayLeaf109e0f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf109e0f0Storage
{
    ~ArrayLeaf109e0f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf109e0f0Size
{
    ~ArrayLeaf109e0f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf109e0f0 : public ArrayLeaf109e0f0Storage, public ArrayLeaf109e0f0Size
{
    ~ArrayLeaf109e0f0();  // compared: 0x109e0f0
};

void FreeArrayLeaf109e0f0(ArrayLeaf109e0f0* array);
