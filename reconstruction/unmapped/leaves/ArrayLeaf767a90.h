// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767a90, ArrayLeaf767a90Storage, ArrayLeaf767a90Size, FreeArrayLeaf767a90, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767a90Storage
{
    ~ArrayLeaf767a90Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767a90Size
{
    ~ArrayLeaf767a90Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767a90 : public ArrayLeaf767a90Storage, public ArrayLeaf767a90Size
{
    ~ArrayLeaf767a90();  // compared: 0x767a90
};

void FreeArrayLeaf767a90(ArrayLeaf767a90* array);
