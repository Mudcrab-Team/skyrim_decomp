// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767bb0, ArrayLeaf767bb0Storage, ArrayLeaf767bb0Size, FreeArrayLeaf767bb0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767bb0Storage
{
    ~ArrayLeaf767bb0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767bb0Size
{
    ~ArrayLeaf767bb0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767bb0 : public ArrayLeaf767bb0Storage, public ArrayLeaf767bb0Size
{
    ~ArrayLeaf767bb0();  // compared: 0x767bb0
};

void FreeArrayLeaf767bb0(ArrayLeaf767bb0* array);
