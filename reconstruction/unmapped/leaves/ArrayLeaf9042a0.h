// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9042a0, ArrayLeaf9042a0Storage, ArrayLeaf9042a0Size, FreeArrayLeaf9042a0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9042a0Storage
{
    ~ArrayLeaf9042a0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9042a0Size
{
    ~ArrayLeaf9042a0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9042a0 : public ArrayLeaf9042a0Storage, public ArrayLeaf9042a0Size
{
    ~ArrayLeaf9042a0();  // compared: 0x9042a0
};

void FreeArrayLeaf9042a0(ArrayLeaf9042a0* array);
