// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf585780, ArrayLeaf585780Storage, ArrayLeaf585780Size, FreeArrayLeaf585780, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf585780Storage
{
    ~ArrayLeaf585780Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf585780Size
{
    ~ArrayLeaf585780Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf585780 : public ArrayLeaf585780Storage, public ArrayLeaf585780Size
{
    ~ArrayLeaf585780();  // compared: 0x585780
};

void FreeArrayLeaf585780(ArrayLeaf585780* array);
