// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf55c0e0, ArrayLeaf55c0e0Storage, ArrayLeaf55c0e0Size, FreeArrayLeaf55c0e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf55c0e0Storage
{
    ~ArrayLeaf55c0e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf55c0e0Size
{
    ~ArrayLeaf55c0e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf55c0e0 : public ArrayLeaf55c0e0Storage, public ArrayLeaf55c0e0Size
{
    ~ArrayLeaf55c0e0();  // compared: 0x55c0e0
};

void FreeArrayLeaf55c0e0(ArrayLeaf55c0e0* array);
