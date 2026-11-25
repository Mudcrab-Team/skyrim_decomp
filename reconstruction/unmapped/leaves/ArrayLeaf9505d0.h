// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9505d0, ArrayLeaf9505d0Storage, ArrayLeaf9505d0Size, FreeArrayLeaf9505d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9505d0Storage
{
    ~ArrayLeaf9505d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9505d0Size
{
    ~ArrayLeaf9505d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9505d0 : public ArrayLeaf9505d0Storage, public ArrayLeaf9505d0Size
{
    ~ArrayLeaf9505d0();  // compared: 0x9505d0
};

void FreeArrayLeaf9505d0(ArrayLeaf9505d0* array);
