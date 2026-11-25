// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4c1d00, ArrayLeaf4c1d00Storage, ArrayLeaf4c1d00Size, FreeArrayLeaf4c1d00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4c1d00Storage
{
    ~ArrayLeaf4c1d00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4c1d00Size
{
    ~ArrayLeaf4c1d00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4c1d00 : public ArrayLeaf4c1d00Storage, public ArrayLeaf4c1d00Size
{
    ~ArrayLeaf4c1d00();  // compared: 0x4c1d00
};

void FreeArrayLeaf4c1d00(ArrayLeaf4c1d00* array);
