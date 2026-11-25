// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafbd7f20, ArrayLeafbd7f20Storage, ArrayLeafbd7f20Size, FreeArrayLeafbd7f20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafbd7f20Storage
{
    ~ArrayLeafbd7f20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafbd7f20Size
{
    ~ArrayLeafbd7f20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafbd7f20 : public ArrayLeafbd7f20Storage, public ArrayLeafbd7f20Size
{
    ~ArrayLeafbd7f20();  // compared: 0xbd7f20
};

void FreeArrayLeafbd7f20(ArrayLeafbd7f20* array);
