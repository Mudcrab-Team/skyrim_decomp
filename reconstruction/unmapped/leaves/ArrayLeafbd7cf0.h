// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafbd7cf0, ArrayLeafbd7cf0Storage, ArrayLeafbd7cf0Size, FreeArrayLeafbd7cf0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafbd7cf0Storage
{
    ~ArrayLeafbd7cf0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafbd7cf0Size
{
    ~ArrayLeafbd7cf0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafbd7cf0 : public ArrayLeafbd7cf0Storage, public ArrayLeafbd7cf0Size
{
    ~ArrayLeafbd7cf0();  // compared: 0xbd7cf0
};

void FreeArrayLeafbd7cf0(ArrayLeafbd7cf0* array);
