// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf12501c0, ArrayLeaf12501c0Storage, ArrayLeaf12501c0Size, FreeArrayLeaf12501c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf12501c0Storage
{
    ~ArrayLeaf12501c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf12501c0Size
{
    ~ArrayLeaf12501c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf12501c0 : public ArrayLeaf12501c0Storage, public ArrayLeaf12501c0Size
{
    ~ArrayLeaf12501c0();  // compared: 0x12501c0
};

void FreeArrayLeaf12501c0(ArrayLeaf12501c0* array);
