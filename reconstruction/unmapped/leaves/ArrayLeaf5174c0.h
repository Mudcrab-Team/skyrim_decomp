// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf5174c0, ArrayLeaf5174c0Storage, ArrayLeaf5174c0Size, FreeArrayLeaf5174c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf5174c0Storage
{
    ~ArrayLeaf5174c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf5174c0Size
{
    ~ArrayLeaf5174c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf5174c0 : public ArrayLeaf5174c0Storage, public ArrayLeaf5174c0Size
{
    ~ArrayLeaf5174c0();  // compared: 0x5174c0
};

void FreeArrayLeaf5174c0(ArrayLeaf5174c0* array);
