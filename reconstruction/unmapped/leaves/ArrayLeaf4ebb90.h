// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4ebb90, ArrayLeaf4ebb90Storage, ArrayLeaf4ebb90Size, FreeArrayLeaf4ebb90, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4ebb90Storage
{
    ~ArrayLeaf4ebb90Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4ebb90Size
{
    ~ArrayLeaf4ebb90Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4ebb90 : public ArrayLeaf4ebb90Storage, public ArrayLeaf4ebb90Size
{
    ~ArrayLeaf4ebb90();  // compared: 0x4ebb90
};

void FreeArrayLeaf4ebb90(ArrayLeaf4ebb90* array);
