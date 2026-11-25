// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf620040, ArrayLeaf620040Storage, ArrayLeaf620040Size, FreeArrayLeaf620040, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf620040Storage
{
    ~ArrayLeaf620040Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf620040Size
{
    ~ArrayLeaf620040Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf620040 : public ArrayLeaf620040Storage, public ArrayLeaf620040Size
{
    ~ArrayLeaf620040();  // compared: 0x620040
};

void FreeArrayLeaf620040(ArrayLeaf620040* array);
