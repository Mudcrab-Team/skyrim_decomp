// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1599700, ArrayLeaf1599700Storage, ArrayLeaf1599700Size, FreeArrayLeaf1599700, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1599700Storage
{
    ~ArrayLeaf1599700Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1599700Size
{
    ~ArrayLeaf1599700Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1599700 : public ArrayLeaf1599700Storage, public ArrayLeaf1599700Size
{
    ~ArrayLeaf1599700();  // compared: 0x1599700
};

void FreeArrayLeaf1599700(ArrayLeaf1599700* array);
