// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafcfa0b0, ArrayLeafcfa0b0Storage, ArrayLeafcfa0b0Size, FreeArrayLeafcfa0b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafcfa0b0Storage
{
    ~ArrayLeafcfa0b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafcfa0b0Size
{
    ~ArrayLeafcfa0b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafcfa0b0 : public ArrayLeafcfa0b0Storage, public ArrayLeafcfa0b0Size
{
    ~ArrayLeafcfa0b0();  // compared: 0xcfa0b0
};

void FreeArrayLeafcfa0b0(ArrayLeafcfa0b0* array);
