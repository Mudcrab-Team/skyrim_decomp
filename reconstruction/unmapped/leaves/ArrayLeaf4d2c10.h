// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4d2c10, ArrayLeaf4d2c10Storage, ArrayLeaf4d2c10Size, FreeArrayLeaf4d2c10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4d2c10Storage
{
    ~ArrayLeaf4d2c10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4d2c10Size
{
    ~ArrayLeaf4d2c10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4d2c10 : public ArrayLeaf4d2c10Storage, public ArrayLeaf4d2c10Size
{
    ~ArrayLeaf4d2c10();  // compared: 0x4d2c10
};

void FreeArrayLeaf4d2c10(ArrayLeaf4d2c10* array);
