// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf8ba240, ArrayLeaf8ba240Storage, ArrayLeaf8ba240Size, FreeArrayLeaf8ba240, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf8ba240Storage
{
    ~ArrayLeaf8ba240Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf8ba240Size
{
    ~ArrayLeaf8ba240Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf8ba240 : public ArrayLeaf8ba240Storage, public ArrayLeaf8ba240Size
{
    ~ArrayLeaf8ba240();  // compared: 0x8ba240
};

void FreeArrayLeaf8ba240(ArrayLeaf8ba240* array);
