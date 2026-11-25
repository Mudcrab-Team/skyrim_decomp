// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf960a00, ArrayLeaf960a00Storage, ArrayLeaf960a00Size, FreeArrayLeaf960a00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf960a00Storage
{
    ~ArrayLeaf960a00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf960a00Size
{
    ~ArrayLeaf960a00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf960a00 : public ArrayLeaf960a00Storage, public ArrayLeaf960a00Size
{
    ~ArrayLeaf960a00();  // compared: 0x960a00
};

void FreeArrayLeaf960a00(ArrayLeaf960a00* array);
