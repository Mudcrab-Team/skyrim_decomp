// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6368a0, ArrayLeaf6368a0Storage, ArrayLeaf6368a0Size, FreeArrayLeaf6368a0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6368a0Storage
{
    ~ArrayLeaf6368a0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6368a0Size
{
    ~ArrayLeaf6368a0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6368a0 : public ArrayLeaf6368a0Storage, public ArrayLeaf6368a0Size
{
    ~ArrayLeaf6368a0();  // compared: 0x6368a0
};

void FreeArrayLeaf6368a0(ArrayLeaf6368a0* array);
