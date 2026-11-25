// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf98c4d0, ArrayLeaf98c4d0Storage, ArrayLeaf98c4d0Size, FreeArrayLeaf98c4d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf98c4d0Storage
{
    ~ArrayLeaf98c4d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf98c4d0Size
{
    ~ArrayLeaf98c4d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf98c4d0 : public ArrayLeaf98c4d0Storage, public ArrayLeaf98c4d0Size
{
    ~ArrayLeaf98c4d0();  // compared: 0x98c4d0
};

void FreeArrayLeaf98c4d0(ArrayLeaf98c4d0* array);
