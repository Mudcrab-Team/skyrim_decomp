// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1061490, ArrayLeaf1061490Storage, ArrayLeaf1061490Size, FreeArrayLeaf1061490, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1061490Storage
{
    ~ArrayLeaf1061490Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1061490Size
{
    ~ArrayLeaf1061490Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1061490 : public ArrayLeaf1061490Storage, public ArrayLeaf1061490Size
{
    ~ArrayLeaf1061490();  // compared: 0x1061490
};

void FreeArrayLeaf1061490(ArrayLeaf1061490* array);
