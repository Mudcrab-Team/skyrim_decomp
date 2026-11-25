// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6ba230, ArrayLeaf6ba230Storage, ArrayLeaf6ba230Size, FreeArrayLeaf6ba230, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6ba230Storage
{
    ~ArrayLeaf6ba230Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6ba230Size
{
    ~ArrayLeaf6ba230Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6ba230 : public ArrayLeaf6ba230Storage, public ArrayLeaf6ba230Size
{
    ~ArrayLeaf6ba230();  // compared: 0x6ba230
};

void FreeArrayLeaf6ba230(ArrayLeaf6ba230* array);
