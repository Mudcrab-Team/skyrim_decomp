// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafeda730, ArrayLeafeda730Storage, ArrayLeafeda730Size, FreeArrayLeafeda730, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafeda730Storage
{
    ~ArrayLeafeda730Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafeda730Size
{
    ~ArrayLeafeda730Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafeda730 : public ArrayLeafeda730Storage, public ArrayLeafeda730Size
{
    ~ArrayLeafeda730();  // compared: 0xeda730
};

void FreeArrayLeafeda730(ArrayLeafeda730* array);
