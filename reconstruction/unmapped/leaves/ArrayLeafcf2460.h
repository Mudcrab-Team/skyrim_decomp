// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafcf2460, ArrayLeafcf2460Storage, ArrayLeafcf2460Size, FreeArrayLeafcf2460, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafcf2460Storage
{
    ~ArrayLeafcf2460Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafcf2460Size
{
    ~ArrayLeafcf2460Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafcf2460 : public ArrayLeafcf2460Storage, public ArrayLeafcf2460Size
{
    ~ArrayLeafcf2460();  // compared: 0xcf2460
};

void FreeArrayLeafcf2460(ArrayLeafcf2460* array);
