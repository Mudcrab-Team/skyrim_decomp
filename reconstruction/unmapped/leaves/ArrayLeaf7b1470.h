// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf7b1470, ArrayLeaf7b1470Storage, ArrayLeaf7b1470Size, FreeArrayLeaf7b1470, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf7b1470Storage
{
    ~ArrayLeaf7b1470Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf7b1470Size
{
    ~ArrayLeaf7b1470Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf7b1470 : public ArrayLeaf7b1470Storage, public ArrayLeaf7b1470Size
{
    ~ArrayLeaf7b1470();  // compared: 0x7b1470
};

void FreeArrayLeaf7b1470(ArrayLeaf7b1470* array);
