// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafce1bc0, ArrayLeafce1bc0Storage, ArrayLeafce1bc0Size, FreeArrayLeafce1bc0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafce1bc0Storage
{
    ~ArrayLeafce1bc0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafce1bc0Size
{
    ~ArrayLeafce1bc0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafce1bc0 : public ArrayLeafce1bc0Storage, public ArrayLeafce1bc0Size
{
    ~ArrayLeafce1bc0();  // compared: 0xce1bc0
};

void FreeArrayLeafce1bc0(ArrayLeafce1bc0* array);
