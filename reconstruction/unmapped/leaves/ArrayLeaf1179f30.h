// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1179f30, ArrayLeaf1179f30Storage, ArrayLeaf1179f30Size, FreeArrayLeaf1179f30, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1179f30Storage
{
    ~ArrayLeaf1179f30Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1179f30Size
{
    ~ArrayLeaf1179f30Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1179f30 : public ArrayLeaf1179f30Storage, public ArrayLeaf1179f30Size
{
    ~ArrayLeaf1179f30();  // compared: 0x1179f30
};

void FreeArrayLeaf1179f30(ArrayLeaf1179f30* array);
