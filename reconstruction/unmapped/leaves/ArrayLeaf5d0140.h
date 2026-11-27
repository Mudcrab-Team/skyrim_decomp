// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf5d0140, ArrayLeaf5d0140Storage, ArrayLeaf5d0140Size, FreeArrayLeaf5d0140, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf5d0140Storage
{
    ~ArrayLeaf5d0140Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf5d0140Size
{
    ~ArrayLeaf5d0140Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf5d0140 : public ArrayLeaf5d0140Storage, public ArrayLeaf5d0140Size
{
    ~ArrayLeaf5d0140();  // compared: 0x5d0140
};

void FreeArrayLeaf5d0140(ArrayLeaf5d0140* array);
