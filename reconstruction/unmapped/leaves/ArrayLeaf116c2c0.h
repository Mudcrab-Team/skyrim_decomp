// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf116c2c0, ArrayLeaf116c2c0Storage, ArrayLeaf116c2c0Size, FreeArrayLeaf116c2c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf116c2c0Storage
{
    ~ArrayLeaf116c2c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf116c2c0Size
{
    ~ArrayLeaf116c2c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf116c2c0 : public ArrayLeaf116c2c0Storage, public ArrayLeaf116c2c0Size
{
    ~ArrayLeaf116c2c0();  // compared: 0x116c2c0
};

void FreeArrayLeaf116c2c0(ArrayLeaf116c2c0* array);
