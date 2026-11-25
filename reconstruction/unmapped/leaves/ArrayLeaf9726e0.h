// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9726e0, ArrayLeaf9726e0Storage, ArrayLeaf9726e0Size, FreeArrayLeaf9726e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9726e0Storage
{
    ~ArrayLeaf9726e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9726e0Size
{
    ~ArrayLeaf9726e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9726e0 : public ArrayLeaf9726e0Storage, public ArrayLeaf9726e0Size
{
    ~ArrayLeaf9726e0();  // compared: 0x9726e0
};

void FreeArrayLeaf9726e0(ArrayLeaf9726e0* array);
