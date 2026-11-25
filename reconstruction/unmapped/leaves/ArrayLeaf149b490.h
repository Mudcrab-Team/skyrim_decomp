// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf149b490, ArrayLeaf149b490Storage, ArrayLeaf149b490Size, FreeArrayLeaf149b490, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf149b490Storage
{
    ~ArrayLeaf149b490Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf149b490Size
{
    ~ArrayLeaf149b490Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf149b490 : public ArrayLeaf149b490Storage, public ArrayLeaf149b490Size
{
    ~ArrayLeaf149b490();  // compared: 0x149b490
};

void FreeArrayLeaf149b490(ArrayLeaf149b490* array);
