// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9a4710, ArrayLeaf9a4710Storage, ArrayLeaf9a4710Size, FreeArrayLeaf9a4710, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9a4710Storage
{
    ~ArrayLeaf9a4710Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9a4710Size
{
    ~ArrayLeaf9a4710Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9a4710 : public ArrayLeaf9a4710Storage, public ArrayLeaf9a4710Size
{
    ~ArrayLeaf9a4710();  // compared: 0x9a4710
};

void FreeArrayLeaf9a4710(ArrayLeaf9a4710* array);
