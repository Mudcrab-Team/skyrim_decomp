// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6d0440, ArrayLeaf6d0440Storage, ArrayLeaf6d0440Size, FreeArrayLeaf6d0440, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6d0440Storage
{
    ~ArrayLeaf6d0440Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6d0440Size
{
    ~ArrayLeaf6d0440Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6d0440 : public ArrayLeaf6d0440Storage, public ArrayLeaf6d0440Size
{
    ~ArrayLeaf6d0440();  // compared: 0x6d0440
};

void FreeArrayLeaf6d0440(ArrayLeaf6d0440* array);
