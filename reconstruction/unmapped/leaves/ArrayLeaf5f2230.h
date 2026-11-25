// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf5f2230, ArrayLeaf5f2230Storage, ArrayLeaf5f2230Size, FreeArrayLeaf5f2230, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf5f2230Storage
{
    ~ArrayLeaf5f2230Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf5f2230Size
{
    ~ArrayLeaf5f2230Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf5f2230 : public ArrayLeaf5f2230Storage, public ArrayLeaf5f2230Size
{
    ~ArrayLeaf5f2230();  // compared: 0x5f2230
};

void FreeArrayLeaf5f2230(ArrayLeaf5f2230* array);
