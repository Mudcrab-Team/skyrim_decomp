// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767670, ArrayLeaf767670Storage, ArrayLeaf767670Size, FreeArrayLeaf767670, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767670Storage
{
    ~ArrayLeaf767670Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767670Size
{
    ~ArrayLeaf767670Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767670 : public ArrayLeaf767670Storage, public ArrayLeaf767670Size
{
    ~ArrayLeaf767670();  // compared: 0x767670
};

void FreeArrayLeaf767670(ArrayLeaf767670* array);
