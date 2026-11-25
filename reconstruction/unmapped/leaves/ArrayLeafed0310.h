// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafed0310, ArrayLeafed0310Storage, ArrayLeafed0310Size, FreeArrayLeafed0310, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafed0310Storage
{
    ~ArrayLeafed0310Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafed0310Size
{
    ~ArrayLeafed0310Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafed0310 : public ArrayLeafed0310Storage, public ArrayLeafed0310Size
{
    ~ArrayLeafed0310();  // compared: 0xed0310
};

void FreeArrayLeafed0310(ArrayLeafed0310* array);
