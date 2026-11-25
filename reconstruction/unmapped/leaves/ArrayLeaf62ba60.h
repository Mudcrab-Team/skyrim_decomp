// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf62ba60, ArrayLeaf62ba60Storage, ArrayLeaf62ba60Size, FreeArrayLeaf62ba60, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf62ba60Storage
{
    ~ArrayLeaf62ba60Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf62ba60Size
{
    ~ArrayLeaf62ba60Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf62ba60 : public ArrayLeaf62ba60Storage, public ArrayLeaf62ba60Size
{
    ~ArrayLeaf62ba60();  // compared: 0x62ba60
};

void FreeArrayLeaf62ba60(ArrayLeaf62ba60* array);
