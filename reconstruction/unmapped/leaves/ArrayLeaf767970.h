// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767970, ArrayLeaf767970Storage, ArrayLeaf767970Size, FreeArrayLeaf767970, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767970Storage
{
    ~ArrayLeaf767970Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767970Size
{
    ~ArrayLeaf767970Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767970 : public ArrayLeaf767970Storage, public ArrayLeaf767970Size
{
    ~ArrayLeaf767970();  // compared: 0x767970
};

void FreeArrayLeaf767970(ArrayLeaf767970* array);
