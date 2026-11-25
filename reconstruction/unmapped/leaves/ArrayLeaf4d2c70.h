// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4d2c70, ArrayLeaf4d2c70Storage, ArrayLeaf4d2c70Size, FreeArrayLeaf4d2c70, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4d2c70Storage
{
    ~ArrayLeaf4d2c70Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4d2c70Size
{
    ~ArrayLeaf4d2c70Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4d2c70 : public ArrayLeaf4d2c70Storage, public ArrayLeaf4d2c70Size
{
    ~ArrayLeaf4d2c70();  // compared: 0x4d2c70
};

void FreeArrayLeaf4d2c70(ArrayLeaf4d2c70* array);
