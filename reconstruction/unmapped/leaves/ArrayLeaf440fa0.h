// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf440fa0, ArrayLeaf440fa0Storage, ArrayLeaf440fa0Size, FreeArrayLeaf440fa0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf440fa0Storage
{
    ~ArrayLeaf440fa0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf440fa0Size
{
    ~ArrayLeaf440fa0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf440fa0 : public ArrayLeaf440fa0Storage, public ArrayLeaf440fa0Size
{
    ~ArrayLeaf440fa0();  // compared: 0x440fa0
};

void FreeArrayLeaf440fa0(ArrayLeaf440fa0* array);
