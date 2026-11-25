// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf126da60, ArrayLeaf126da60Storage, ArrayLeaf126da60Size, FreeArrayLeaf126da60, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf126da60Storage
{
    ~ArrayLeaf126da60Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf126da60Size
{
    ~ArrayLeaf126da60Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf126da60 : public ArrayLeaf126da60Storage, public ArrayLeaf126da60Size
{
    ~ArrayLeaf126da60();  // compared: 0x126da60
};

void FreeArrayLeaf126da60(ArrayLeaf126da60* array);
