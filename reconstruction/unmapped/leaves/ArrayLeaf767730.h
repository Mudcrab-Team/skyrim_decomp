// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767730, ArrayLeaf767730Storage, ArrayLeaf767730Size, FreeArrayLeaf767730, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767730Storage
{
    ~ArrayLeaf767730Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767730Size
{
    ~ArrayLeaf767730Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767730 : public ArrayLeaf767730Storage, public ArrayLeaf767730Size
{
    ~ArrayLeaf767730();  // compared: 0x767730
};

void FreeArrayLeaf767730(ArrayLeaf767730* array);
