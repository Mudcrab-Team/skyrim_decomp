// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf94c930, ArrayLeaf94c930Storage, ArrayLeaf94c930Size, FreeArrayLeaf94c930, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf94c930Storage
{
    ~ArrayLeaf94c930Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf94c930Size
{
    ~ArrayLeaf94c930Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf94c930 : public ArrayLeaf94c930Storage, public ArrayLeaf94c930Size
{
    ~ArrayLeaf94c930();  // compared: 0x94c930
};

void FreeArrayLeaf94c930(ArrayLeaf94c930* array);
