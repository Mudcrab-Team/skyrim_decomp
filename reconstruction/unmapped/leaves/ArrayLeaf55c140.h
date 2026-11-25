// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf55c140, ArrayLeaf55c140Storage, ArrayLeaf55c140Size, FreeArrayLeaf55c140, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf55c140Storage
{
    ~ArrayLeaf55c140Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf55c140Size
{
    ~ArrayLeaf55c140Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf55c140 : public ArrayLeaf55c140Storage, public ArrayLeaf55c140Size
{
    ~ArrayLeaf55c140();  // compared: 0x55c140
};

void FreeArrayLeaf55c140(ArrayLeaf55c140* array);
