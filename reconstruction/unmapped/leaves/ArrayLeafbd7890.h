// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafbd7890, ArrayLeafbd7890Storage, ArrayLeafbd7890Size, FreeArrayLeafbd7890, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafbd7890Storage
{
    ~ArrayLeafbd7890Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafbd7890Size
{
    ~ArrayLeafbd7890Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafbd7890 : public ArrayLeafbd7890Storage, public ArrayLeafbd7890Size
{
    ~ArrayLeafbd7890();  // compared: 0xbd7890
};

void FreeArrayLeafbd7890(ArrayLeafbd7890* array);
