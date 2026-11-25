// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9a46b0, ArrayLeaf9a46b0Storage, ArrayLeaf9a46b0Size, FreeArrayLeaf9a46b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9a46b0Storage
{
    ~ArrayLeaf9a46b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9a46b0Size
{
    ~ArrayLeaf9a46b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9a46b0 : public ArrayLeaf9a46b0Storage, public ArrayLeaf9a46b0Size
{
    ~ArrayLeaf9a46b0();  // compared: 0x9a46b0
};

void FreeArrayLeaf9a46b0(ArrayLeaf9a46b0* array);
