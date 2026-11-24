// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf11e93e0, ArrayLeaf11e93e0Storage, ArrayLeaf11e93e0Size, FreeArrayLeaf11e93e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf11e93e0Storage
{
    ~ArrayLeaf11e93e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf11e93e0Size
{
    ~ArrayLeaf11e93e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf11e93e0 : public ArrayLeaf11e93e0Storage, public ArrayLeaf11e93e0Size
{
    ~ArrayLeaf11e93e0();  // compared: 0x11e93e0
};

void FreeArrayLeaf11e93e0(ArrayLeaf11e93e0* array);
