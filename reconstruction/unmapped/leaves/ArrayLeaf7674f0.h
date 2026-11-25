// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf7674f0, ArrayLeaf7674f0Storage, ArrayLeaf7674f0Size, FreeArrayLeaf7674f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf7674f0Storage
{
    ~ArrayLeaf7674f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf7674f0Size
{
    ~ArrayLeaf7674f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf7674f0 : public ArrayLeaf7674f0Storage, public ArrayLeaf7674f0Size
{
    ~ArrayLeaf7674f0();  // compared: 0x7674f0
};

void FreeArrayLeaf7674f0(ArrayLeaf7674f0* array);
