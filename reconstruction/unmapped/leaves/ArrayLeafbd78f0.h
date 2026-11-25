// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafbd78f0, ArrayLeafbd78f0Storage, ArrayLeafbd78f0Size, FreeArrayLeafbd78f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafbd78f0Storage
{
    ~ArrayLeafbd78f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafbd78f0Size
{
    ~ArrayLeafbd78f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafbd78f0 : public ArrayLeafbd78f0Storage, public ArrayLeafbd78f0Size
{
    ~ArrayLeafbd78f0();  // compared: 0xbd78f0
};

void FreeArrayLeafbd78f0(ArrayLeafbd78f0* array);
