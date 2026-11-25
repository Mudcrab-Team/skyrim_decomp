// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf975580, ArrayLeaf975580Storage, ArrayLeaf975580Size, FreeArrayLeaf975580, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf975580Storage
{
    ~ArrayLeaf975580Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf975580Size
{
    ~ArrayLeaf975580Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf975580 : public ArrayLeaf975580Storage, public ArrayLeaf975580Size
{
    ~ArrayLeaf975580();  // compared: 0x975580
};

void FreeArrayLeaf975580(ArrayLeaf975580* array);
