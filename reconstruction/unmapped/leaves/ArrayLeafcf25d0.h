// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafcf25d0, ArrayLeafcf25d0Storage, ArrayLeafcf25d0Size, FreeArrayLeafcf25d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafcf25d0Storage
{
    ~ArrayLeafcf25d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafcf25d0Size
{
    ~ArrayLeafcf25d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafcf25d0 : public ArrayLeafcf25d0Storage, public ArrayLeafcf25d0Size
{
    ~ArrayLeafcf25d0();  // compared: 0xcf25d0
};

void FreeArrayLeafcf25d0(ArrayLeafcf25d0* array);
