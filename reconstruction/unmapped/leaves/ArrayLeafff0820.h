// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafff0820, ArrayLeafff0820Storage, ArrayLeafff0820Size, FreeArrayLeafff0820, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafff0820Storage
{
    ~ArrayLeafff0820Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafff0820Size
{
    ~ArrayLeafff0820Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafff0820 : public ArrayLeafff0820Storage, public ArrayLeafff0820Size
{
    ~ArrayLeafff0820();  // compared: 0xff0820
};

void FreeArrayLeafff0820(ArrayLeafff0820* array);
