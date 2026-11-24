// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafcfbdf0, ArrayLeafcfbdf0Storage, ArrayLeafcfbdf0Size, FreeArrayLeafcfbdf0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafcfbdf0Storage
{
    ~ArrayLeafcfbdf0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafcfbdf0Size
{
    ~ArrayLeafcfbdf0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafcfbdf0 : public ArrayLeafcfbdf0Storage, public ArrayLeafcfbdf0Size
{
    ~ArrayLeafcfbdf0();  // compared: 0xcfbdf0
};

void FreeArrayLeafcfbdf0(ArrayLeafcfbdf0* array);
