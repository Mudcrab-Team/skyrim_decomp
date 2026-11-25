// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf646d00, ArrayLeaf646d00Storage, ArrayLeaf646d00Size, FreeArrayLeaf646d00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf646d00Storage
{
    ~ArrayLeaf646d00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf646d00Size
{
    ~ArrayLeaf646d00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf646d00 : public ArrayLeaf646d00Storage, public ArrayLeaf646d00Size
{
    ~ArrayLeaf646d00();  // compared: 0x646d00
};

void FreeArrayLeaf646d00(ArrayLeaf646d00* array);
