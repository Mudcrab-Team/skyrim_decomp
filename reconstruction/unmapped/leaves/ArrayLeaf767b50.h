// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767b50, ArrayLeaf767b50Storage, ArrayLeaf767b50Size, FreeArrayLeaf767b50, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767b50Storage
{
    ~ArrayLeaf767b50Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767b50Size
{
    ~ArrayLeaf767b50Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767b50 : public ArrayLeaf767b50Storage, public ArrayLeaf767b50Size
{
    ~ArrayLeaf767b50();  // compared: 0x767b50
};

void FreeArrayLeaf767b50(ArrayLeaf767b50* array);
