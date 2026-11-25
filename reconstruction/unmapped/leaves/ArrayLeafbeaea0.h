// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafbeaea0, ArrayLeafbeaea0Storage, ArrayLeafbeaea0Size, FreeArrayLeafbeaea0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafbeaea0Storage
{
    ~ArrayLeafbeaea0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafbeaea0Size
{
    ~ArrayLeafbeaea0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafbeaea0 : public ArrayLeafbeaea0Storage, public ArrayLeafbeaea0Size
{
    ~ArrayLeafbeaea0();  // compared: 0xbeaea0
};

void FreeArrayLeafbeaea0(ArrayLeafbeaea0* array);
