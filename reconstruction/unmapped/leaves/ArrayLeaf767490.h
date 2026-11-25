// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767490, ArrayLeaf767490Storage, ArrayLeaf767490Size, FreeArrayLeaf767490, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767490Storage
{
    ~ArrayLeaf767490Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767490Size
{
    ~ArrayLeaf767490Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767490 : public ArrayLeaf767490Storage, public ArrayLeaf767490Size
{
    ~ArrayLeaf767490();  // compared: 0x767490
};

void FreeArrayLeaf767490(ArrayLeaf767490* array);
