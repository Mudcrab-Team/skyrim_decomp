// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767610, ArrayLeaf767610Storage, ArrayLeaf767610Size, FreeArrayLeaf767610, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767610Storage
{
    ~ArrayLeaf767610Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767610Size
{
    ~ArrayLeaf767610Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767610 : public ArrayLeaf767610Storage, public ArrayLeaf767610Size
{
    ~ArrayLeaf767610();  // compared: 0x767610
};

void FreeArrayLeaf767610(ArrayLeaf767610* array);
