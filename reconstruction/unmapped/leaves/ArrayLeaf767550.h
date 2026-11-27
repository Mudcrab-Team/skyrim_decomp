// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767550, ArrayLeaf767550Storage, ArrayLeaf767550Size, FreeArrayLeaf767550, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767550Storage
{
    ~ArrayLeaf767550Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767550Size
{
    ~ArrayLeaf767550Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767550 : public ArrayLeaf767550Storage, public ArrayLeaf767550Size
{
    ~ArrayLeaf767550();  // compared: 0x767550
};

void FreeArrayLeaf767550(ArrayLeaf767550* array);
