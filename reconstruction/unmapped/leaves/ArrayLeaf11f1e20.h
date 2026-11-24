// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf11f1e20, ArrayLeaf11f1e20Storage, ArrayLeaf11f1e20Size, FreeArrayLeaf11f1e20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf11f1e20Storage
{
    ~ArrayLeaf11f1e20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf11f1e20Size
{
    ~ArrayLeaf11f1e20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf11f1e20 : public ArrayLeaf11f1e20Storage, public ArrayLeaf11f1e20Size
{
    ~ArrayLeaf11f1e20();  // compared: 0x11f1e20
};

void FreeArrayLeaf11f1e20(ArrayLeaf11f1e20* array);
