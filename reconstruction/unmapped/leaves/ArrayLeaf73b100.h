// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf73b100, ArrayLeaf73b100Storage, ArrayLeaf73b100Size, FreeArrayLeaf73b100, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf73b100Storage
{
    ~ArrayLeaf73b100Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf73b100Size
{
    ~ArrayLeaf73b100Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf73b100 : public ArrayLeaf73b100Storage, public ArrayLeaf73b100Size
{
    ~ArrayLeaf73b100();  // compared: 0x73b100
};

void FreeArrayLeaf73b100(ArrayLeaf73b100* array);
