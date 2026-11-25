// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767430, ArrayLeaf767430Storage, ArrayLeaf767430Size, FreeArrayLeaf767430, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767430Storage
{
    ~ArrayLeaf767430Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767430Size
{
    ~ArrayLeaf767430Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767430 : public ArrayLeaf767430Storage, public ArrayLeaf767430Size
{
    ~ArrayLeaf767430();  // compared: 0x767430
};

void FreeArrayLeaf767430(ArrayLeaf767430* array);
