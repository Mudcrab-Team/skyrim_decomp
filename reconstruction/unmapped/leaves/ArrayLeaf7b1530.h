// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf7b1530, ArrayLeaf7b1530Storage, ArrayLeaf7b1530Size, FreeArrayLeaf7b1530, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf7b1530Storage
{
    ~ArrayLeaf7b1530Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf7b1530Size
{
    ~ArrayLeaf7b1530Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf7b1530 : public ArrayLeaf7b1530Storage, public ArrayLeaf7b1530Size
{
    ~ArrayLeaf7b1530();  // compared: 0x7b1530
};

void FreeArrayLeaf7b1530(ArrayLeaf7b1530* array);
