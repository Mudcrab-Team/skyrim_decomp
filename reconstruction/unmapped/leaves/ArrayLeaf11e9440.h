// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf11e9440, ArrayLeaf11e9440Storage, ArrayLeaf11e9440Size, FreeArrayLeaf11e9440, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf11e9440Storage
{
    ~ArrayLeaf11e9440Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf11e9440Size
{
    ~ArrayLeaf11e9440Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf11e9440 : public ArrayLeaf11e9440Storage, public ArrayLeaf11e9440Size
{
    ~ArrayLeaf11e9440();  // compared: 0x11e9440
};

void FreeArrayLeaf11e9440(ArrayLeaf11e9440* array);
