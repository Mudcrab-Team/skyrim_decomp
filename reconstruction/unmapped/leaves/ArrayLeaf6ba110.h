// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6ba110, ArrayLeaf6ba110Storage, ArrayLeaf6ba110Size, FreeArrayLeaf6ba110, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6ba110Storage
{
    ~ArrayLeaf6ba110Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6ba110Size
{
    ~ArrayLeaf6ba110Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6ba110 : public ArrayLeaf6ba110Storage, public ArrayLeaf6ba110Size
{
    ~ArrayLeaf6ba110();  // compared: 0x6ba110
};

void FreeArrayLeaf6ba110(ArrayLeaf6ba110* array);
