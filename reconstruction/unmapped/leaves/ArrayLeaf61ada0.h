// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf61ada0, ArrayLeaf61ada0Storage, ArrayLeaf61ada0Size, FreeArrayLeaf61ada0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf61ada0Storage
{
    ~ArrayLeaf61ada0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf61ada0Size
{
    ~ArrayLeaf61ada0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf61ada0 : public ArrayLeaf61ada0Storage, public ArrayLeaf61ada0Size
{
    ~ArrayLeaf61ada0();  // compared: 0x61ada0
};

void FreeArrayLeaf61ada0(ArrayLeaf61ada0* array);
