// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767310, ArrayLeaf767310Storage, ArrayLeaf767310Size, FreeArrayLeaf767310, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767310Storage
{
    ~ArrayLeaf767310Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767310Size
{
    ~ArrayLeaf767310Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767310 : public ArrayLeaf767310Storage, public ArrayLeaf767310Size
{
    ~ArrayLeaf767310();  // compared: 0x767310
};

void FreeArrayLeaf767310(ArrayLeaf767310* array);
