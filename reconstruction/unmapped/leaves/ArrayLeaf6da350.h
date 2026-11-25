// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6da350, ArrayLeaf6da350Storage, ArrayLeaf6da350Size, FreeArrayLeaf6da350, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6da350Storage
{
    ~ArrayLeaf6da350Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6da350Size
{
    ~ArrayLeaf6da350Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6da350 : public ArrayLeaf6da350Storage, public ArrayLeaf6da350Size
{
    ~ArrayLeaf6da350();  // compared: 0x6da350
};

void FreeArrayLeaf6da350(ArrayLeaf6da350* array);
