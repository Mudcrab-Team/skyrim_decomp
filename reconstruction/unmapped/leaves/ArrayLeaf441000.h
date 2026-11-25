// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf441000, ArrayLeaf441000Storage, ArrayLeaf441000Size, FreeArrayLeaf441000, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf441000Storage
{
    ~ArrayLeaf441000Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf441000Size
{
    ~ArrayLeaf441000Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf441000 : public ArrayLeaf441000Storage, public ArrayLeaf441000Size
{
    ~ArrayLeaf441000();  // compared: 0x441000
};

void FreeArrayLeaf441000(ArrayLeaf441000* array);
