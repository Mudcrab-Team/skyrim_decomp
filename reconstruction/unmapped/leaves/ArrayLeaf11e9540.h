// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf11e9540, ArrayLeaf11e9540Storage, ArrayLeaf11e9540Size, FreeArrayLeaf11e9540, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf11e9540Storage
{
    ~ArrayLeaf11e9540Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf11e9540Size
{
    ~ArrayLeaf11e9540Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf11e9540 : public ArrayLeaf11e9540Storage, public ArrayLeaf11e9540Size
{
    ~ArrayLeaf11e9540();  // compared: 0x11e9540
};

void FreeArrayLeaf11e9540(ArrayLeaf11e9540* array);
