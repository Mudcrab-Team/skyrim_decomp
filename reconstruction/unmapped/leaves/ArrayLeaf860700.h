// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf860700, ArrayLeaf860700Storage, ArrayLeaf860700Size, FreeArrayLeaf860700, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf860700Storage
{
    ~ArrayLeaf860700Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf860700Size
{
    ~ArrayLeaf860700Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf860700 : public ArrayLeaf860700Storage, public ArrayLeaf860700Size
{
    ~ArrayLeaf860700();  // compared: 0x860700
};

void FreeArrayLeaf860700(ArrayLeaf860700* array);
