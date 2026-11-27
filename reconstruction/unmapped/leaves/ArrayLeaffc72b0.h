// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaffc72b0, ArrayLeaffc72b0Storage, ArrayLeaffc72b0Size, FreeArrayLeaffc72b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaffc72b0Storage
{
    ~ArrayLeaffc72b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaffc72b0Size
{
    ~ArrayLeaffc72b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaffc72b0 : public ArrayLeaffc72b0Storage, public ArrayLeaffc72b0Size
{
    ~ArrayLeaffc72b0();  // compared: 0xfc72b0
};

void FreeArrayLeaffc72b0(ArrayLeaffc72b0* array);
