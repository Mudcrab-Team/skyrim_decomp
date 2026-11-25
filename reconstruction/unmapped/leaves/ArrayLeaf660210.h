// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf660210, ArrayLeaf660210Storage, ArrayLeaf660210Size, FreeArrayLeaf660210, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf660210Storage
{
    ~ArrayLeaf660210Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf660210Size
{
    ~ArrayLeaf660210Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf660210 : public ArrayLeaf660210Storage, public ArrayLeaf660210Size
{
    ~ArrayLeaf660210();  // compared: 0x660210
};

void FreeArrayLeaf660210(ArrayLeaf660210* array);
