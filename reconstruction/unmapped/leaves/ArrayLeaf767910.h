// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767910, ArrayLeaf767910Storage, ArrayLeaf767910Size, FreeArrayLeaf767910, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767910Storage
{
    ~ArrayLeaf767910Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767910Size
{
    ~ArrayLeaf767910Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767910 : public ArrayLeaf767910Storage, public ArrayLeaf767910Size
{
    ~ArrayLeaf767910();  // compared: 0x767910
};

void FreeArrayLeaf767910(ArrayLeaf767910* array);
