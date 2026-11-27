// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf822850, ArrayLeaf822850Storage, ArrayLeaf822850Size, FreeArrayLeaf822850, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf822850Storage
{
    ~ArrayLeaf822850Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf822850Size
{
    ~ArrayLeaf822850Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf822850 : public ArrayLeaf822850Storage, public ArrayLeaf822850Size
{
    ~ArrayLeaf822850();  // compared: 0x822850
};

void FreeArrayLeaf822850(ArrayLeaf822850* array);
