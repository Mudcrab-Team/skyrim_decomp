// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf955760, ArrayLeaf955760Storage, ArrayLeaf955760Size, FreeArrayLeaf955760, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf955760Storage
{
    ~ArrayLeaf955760Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf955760Size
{
    ~ArrayLeaf955760Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf955760 : public ArrayLeaf955760Storage, public ArrayLeaf955760Size
{
    ~ArrayLeaf955760();  // compared: 0x955760
};

void FreeArrayLeaf955760(ArrayLeaf955760* array);
