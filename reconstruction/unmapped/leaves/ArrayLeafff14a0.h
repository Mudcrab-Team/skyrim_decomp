// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafff14a0, ArrayLeafff14a0Storage, ArrayLeafff14a0Size, FreeArrayLeafff14a0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafff14a0Storage
{
    ~ArrayLeafff14a0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafff14a0Size
{
    ~ArrayLeafff14a0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafff14a0 : public ArrayLeafff14a0Storage, public ArrayLeafff14a0Size
{
    ~ArrayLeafff14a0();  // compared: 0xff14a0
};

void FreeArrayLeafff14a0(ArrayLeafff14a0* array);
