// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaffc3fc0, ArrayLeaffc3fc0Storage, ArrayLeaffc3fc0Size, FreeArrayLeaffc3fc0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaffc3fc0Storage
{
    ~ArrayLeaffc3fc0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaffc3fc0Size
{
    ~ArrayLeaffc3fc0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaffc3fc0 : public ArrayLeaffc3fc0Storage, public ArrayLeaffc3fc0Size
{
    ~ArrayLeaffc3fc0();  // compared: 0xfc3fc0
};

void FreeArrayLeaffc3fc0(ArrayLeaffc3fc0* array);
