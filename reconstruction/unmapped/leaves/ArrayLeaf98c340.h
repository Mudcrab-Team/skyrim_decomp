// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf98c340, ArrayLeaf98c340Storage, ArrayLeaf98c340Size, FreeArrayLeaf98c340, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf98c340Storage
{
    ~ArrayLeaf98c340Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf98c340Size
{
    ~ArrayLeaf98c340Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf98c340 : public ArrayLeaf98c340Storage, public ArrayLeaf98c340Size
{
    ~ArrayLeaf98c340();  // compared: 0x98c340
};

void FreeArrayLeaf98c340(ArrayLeaf98c340* array);
