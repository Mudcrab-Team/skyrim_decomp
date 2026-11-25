// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf14c6830, ArrayLeaf14c6830Storage, ArrayLeaf14c6830Size, FreeArrayLeaf14c6830, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf14c6830Storage
{
    ~ArrayLeaf14c6830Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf14c6830Size
{
    ~ArrayLeaf14c6830Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf14c6830 : public ArrayLeaf14c6830Storage, public ArrayLeaf14c6830Size
{
    ~ArrayLeaf14c6830();  // compared: 0x14c6830
};

void FreeArrayLeaf14c6830(ArrayLeaf14c6830* array);
