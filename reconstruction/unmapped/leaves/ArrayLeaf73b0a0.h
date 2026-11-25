// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf73b0a0, ArrayLeaf73b0a0Storage, ArrayLeaf73b0a0Size, FreeArrayLeaf73b0a0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf73b0a0Storage
{
    ~ArrayLeaf73b0a0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf73b0a0Size
{
    ~ArrayLeaf73b0a0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf73b0a0 : public ArrayLeaf73b0a0Storage, public ArrayLeaf73b0a0Size
{
    ~ArrayLeaf73b0a0();  // compared: 0x73b0a0
};

void FreeArrayLeaf73b0a0(ArrayLeaf73b0a0* array);
