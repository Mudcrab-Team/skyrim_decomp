// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafed0370, ArrayLeafed0370Storage, ArrayLeafed0370Size, FreeArrayLeafed0370, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafed0370Storage
{
    ~ArrayLeafed0370Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafed0370Size
{
    ~ArrayLeafed0370Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafed0370 : public ArrayLeafed0370Storage, public ArrayLeafed0370Size
{
    ~ArrayLeafed0370();  // compared: 0xed0370
};

void FreeArrayLeafed0370(ArrayLeafed0370* array);
