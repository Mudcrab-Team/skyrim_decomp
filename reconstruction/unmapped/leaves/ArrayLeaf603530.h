// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf603530, ArrayLeaf603530Storage, ArrayLeaf603530Size, FreeArrayLeaf603530, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf603530Storage
{
    ~ArrayLeaf603530Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf603530Size
{
    ~ArrayLeaf603530Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf603530 : public ArrayLeaf603530Storage, public ArrayLeaf603530Size
{
    ~ArrayLeaf603530();  // compared: 0x603530
};

void FreeArrayLeaf603530(ArrayLeaf603530* array);
