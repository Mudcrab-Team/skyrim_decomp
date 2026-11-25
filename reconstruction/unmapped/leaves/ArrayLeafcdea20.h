// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafcdea20, ArrayLeafcdea20Storage, ArrayLeafcdea20Size, FreeArrayLeafcdea20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafcdea20Storage
{
    ~ArrayLeafcdea20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafcdea20Size
{
    ~ArrayLeafcdea20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafcdea20 : public ArrayLeafcdea20Storage, public ArrayLeafcdea20Size
{
    ~ArrayLeafcdea20();  // compared: 0xcdea20
};

void FreeArrayLeafcdea20(ArrayLeafcdea20* array);
