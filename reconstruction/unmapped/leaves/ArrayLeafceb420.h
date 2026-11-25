// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafceb420, ArrayLeafceb420Storage, ArrayLeafceb420Size, FreeArrayLeafceb420, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafceb420Storage
{
    ~ArrayLeafceb420Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafceb420Size
{
    ~ArrayLeafceb420Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafceb420 : public ArrayLeafceb420Storage, public ArrayLeafceb420Size
{
    ~ArrayLeafceb420();  // compared: 0xceb420
};

void FreeArrayLeafceb420(ArrayLeafceb420* array);
