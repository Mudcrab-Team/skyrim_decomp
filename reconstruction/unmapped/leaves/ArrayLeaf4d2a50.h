// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4d2a50, ArrayLeaf4d2a50Storage, ArrayLeaf4d2a50Size, FreeArrayLeaf4d2a50, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4d2a50Storage
{
    ~ArrayLeaf4d2a50Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4d2a50Size
{
    ~ArrayLeaf4d2a50Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4d2a50 : public ArrayLeaf4d2a50Storage, public ArrayLeaf4d2a50Size
{
    ~ArrayLeaf4d2a50();  // compared: 0x4d2a50
};

void FreeArrayLeaf4d2a50(ArrayLeaf4d2a50* array);
