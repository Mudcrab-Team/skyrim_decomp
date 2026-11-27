// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf603590, ArrayLeaf603590Storage, ArrayLeaf603590Size, FreeArrayLeaf603590, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf603590Storage
{
    ~ArrayLeaf603590Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf603590Size
{
    ~ArrayLeaf603590Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf603590 : public ArrayLeaf603590Storage, public ArrayLeaf603590Size
{
    ~ArrayLeaf603590();  // compared: 0x603590
};

void FreeArrayLeaf603590(ArrayLeaf603590* array);
