// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4d2ab0, ArrayLeaf4d2ab0Storage, ArrayLeaf4d2ab0Size, FreeArrayLeaf4d2ab0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4d2ab0Storage
{
    ~ArrayLeaf4d2ab0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4d2ab0Size
{
    ~ArrayLeaf4d2ab0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4d2ab0 : public ArrayLeaf4d2ab0Storage, public ArrayLeaf4d2ab0Size
{
    ~ArrayLeaf4d2ab0();  // compared: 0x4d2ab0
};

void FreeArrayLeaf4d2ab0(ArrayLeaf4d2ab0* array);
