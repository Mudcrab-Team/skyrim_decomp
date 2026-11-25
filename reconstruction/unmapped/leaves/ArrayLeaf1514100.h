// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1514100, ArrayLeaf1514100Storage, ArrayLeaf1514100Size, FreeArrayLeaf1514100, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1514100Storage
{
    ~ArrayLeaf1514100Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1514100Size
{
    ~ArrayLeaf1514100Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1514100 : public ArrayLeaf1514100Storage, public ArrayLeaf1514100Size
{
    ~ArrayLeaf1514100();  // compared: 0x1514100
};

void FreeArrayLeaf1514100(ArrayLeaf1514100* array);
