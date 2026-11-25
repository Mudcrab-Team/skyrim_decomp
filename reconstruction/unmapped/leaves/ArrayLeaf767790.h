// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767790, ArrayLeaf767790Storage, ArrayLeaf767790Size, FreeArrayLeaf767790, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767790Storage
{
    ~ArrayLeaf767790Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767790Size
{
    ~ArrayLeaf767790Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767790 : public ArrayLeaf767790Storage, public ArrayLeaf767790Size
{
    ~ArrayLeaf767790();  // compared: 0x767790
};

void FreeArrayLeaf767790(ArrayLeaf767790* array);
