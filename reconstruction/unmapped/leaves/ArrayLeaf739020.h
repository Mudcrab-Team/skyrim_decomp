// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf739020, ArrayLeaf739020Storage, ArrayLeaf739020Size, FreeArrayLeaf739020, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf739020Storage
{
    ~ArrayLeaf739020Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf739020Size
{
    ~ArrayLeaf739020Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf739020 : public ArrayLeaf739020Storage, public ArrayLeaf739020Size
{
    ~ArrayLeaf739020();  // compared: 0x739020
};

void FreeArrayLeaf739020(ArrayLeaf739020* array);
