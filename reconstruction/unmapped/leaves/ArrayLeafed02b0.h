// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafed02b0, ArrayLeafed02b0Storage, ArrayLeafed02b0Size, FreeArrayLeafed02b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafed02b0Storage
{
    ~ArrayLeafed02b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafed02b0Size
{
    ~ArrayLeafed02b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafed02b0 : public ArrayLeafed02b0Storage, public ArrayLeafed02b0Size
{
    ~ArrayLeafed02b0();  // compared: 0xed02b0
};

void FreeArrayLeafed02b0(ArrayLeafed02b0* array);
