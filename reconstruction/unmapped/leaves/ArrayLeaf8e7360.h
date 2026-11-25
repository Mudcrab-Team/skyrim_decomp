// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf8e7360, ArrayLeaf8e7360Storage, ArrayLeaf8e7360Size, FreeArrayLeaf8e7360, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf8e7360Storage
{
    ~ArrayLeaf8e7360Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf8e7360Size
{
    ~ArrayLeaf8e7360Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf8e7360 : public ArrayLeaf8e7360Storage, public ArrayLeaf8e7360Size
{
    ~ArrayLeaf8e7360();  // compared: 0x8e7360
};

void FreeArrayLeaf8e7360(ArrayLeaf8e7360* array);
