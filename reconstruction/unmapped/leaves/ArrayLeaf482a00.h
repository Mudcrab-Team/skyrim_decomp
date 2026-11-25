// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf482a00, ArrayLeaf482a00Storage, ArrayLeaf482a00Size, FreeArrayLeaf482a00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf482a00Storage
{
    ~ArrayLeaf482a00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf482a00Size
{
    ~ArrayLeaf482a00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf482a00 : public ArrayLeaf482a00Storage, public ArrayLeaf482a00Size
{
    ~ArrayLeaf482a00();  // compared: 0x482a00
};

void FreeArrayLeaf482a00(ArrayLeaf482a00* array);
