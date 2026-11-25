// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf640e30, ArrayLeaf640e30Storage, ArrayLeaf640e30Size, FreeArrayLeaf640e30, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf640e30Storage
{
    ~ArrayLeaf640e30Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf640e30Size
{
    ~ArrayLeaf640e30Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf640e30 : public ArrayLeaf640e30Storage, public ArrayLeaf640e30Size
{
    ~ArrayLeaf640e30();  // compared: 0x640e30
};

void FreeArrayLeaf640e30(ArrayLeaf640e30* array);
