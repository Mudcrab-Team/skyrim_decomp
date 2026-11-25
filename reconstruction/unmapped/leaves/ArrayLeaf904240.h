// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf904240, ArrayLeaf904240Storage, ArrayLeaf904240Size, FreeArrayLeaf904240, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf904240Storage
{
    ~ArrayLeaf904240Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf904240Size
{
    ~ArrayLeaf904240Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf904240 : public ArrayLeaf904240Storage, public ArrayLeaf904240Size
{
    ~ArrayLeaf904240();  // compared: 0x904240
};

void FreeArrayLeaf904240(ArrayLeaf904240* array);
