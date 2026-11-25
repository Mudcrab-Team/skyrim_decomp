// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafbd7830, ArrayLeafbd7830Storage, ArrayLeafbd7830Size, FreeArrayLeafbd7830, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafbd7830Storage
{
    ~ArrayLeafbd7830Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafbd7830Size
{
    ~ArrayLeafbd7830Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafbd7830 : public ArrayLeafbd7830Storage, public ArrayLeafbd7830Size
{
    ~ArrayLeafbd7830();  // compared: 0xbd7830
};

void FreeArrayLeafbd7830(ArrayLeafbd7830* array);
