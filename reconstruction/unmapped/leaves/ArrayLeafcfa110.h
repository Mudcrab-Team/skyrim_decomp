// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafcfa110, ArrayLeafcfa110Storage, ArrayLeafcfa110Size, FreeArrayLeafcfa110, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafcfa110Storage
{
    ~ArrayLeafcfa110Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafcfa110Size
{
    ~ArrayLeafcfa110Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafcfa110 : public ArrayLeafcfa110Storage, public ArrayLeafcfa110Size
{
    ~ArrayLeafcfa110();  // compared: 0xcfa110
};

void FreeArrayLeafcfa110(ArrayLeafcfa110* array);
