// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafff98d0, ArrayLeafff98d0Storage, ArrayLeafff98d0Size, FreeArrayLeafff98d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafff98d0Storage
{
    ~ArrayLeafff98d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafff98d0Size
{
    ~ArrayLeafff98d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafff98d0 : public ArrayLeafff98d0Storage, public ArrayLeafff98d0Size
{
    ~ArrayLeafff98d0();  // compared: 0xff98d0
};

void FreeArrayLeafff98d0(ArrayLeafff98d0* array);
