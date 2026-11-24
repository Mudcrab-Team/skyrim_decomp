// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4b8510, ArrayLeaf4b8510Storage, ArrayLeaf4b8510Size, FreeArrayLeaf4b8510, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4b8510Storage
{
    ~ArrayLeaf4b8510Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4b8510Size
{
    ~ArrayLeaf4b8510Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4b8510 : public ArrayLeaf4b8510Storage, public ArrayLeaf4b8510Size
{
    ~ArrayLeaf4b8510();  // compared: 0x4b8510
};

void FreeArrayLeaf4b8510(ArrayLeaf4b8510* array);
