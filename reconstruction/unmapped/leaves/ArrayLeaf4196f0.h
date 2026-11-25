// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4196f0, ArrayLeaf4196f0Storage, ArrayLeaf4196f0Size, FreeArrayLeaf4196f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4196f0Storage
{
    ~ArrayLeaf4196f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4196f0Size
{
    ~ArrayLeaf4196f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4196f0 : public ArrayLeaf4196f0Storage, public ArrayLeaf4196f0Size
{
    ~ArrayLeaf4196f0();  // compared: 0x4196f0
};

void FreeArrayLeaf4196f0(ArrayLeaf4196f0* array);
