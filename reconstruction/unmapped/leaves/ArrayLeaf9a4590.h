// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9a4590, ArrayLeaf9a4590Storage, ArrayLeaf9a4590Size, FreeArrayLeaf9a4590, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9a4590Storage
{
    ~ArrayLeaf9a4590Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9a4590Size
{
    ~ArrayLeaf9a4590Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9a4590 : public ArrayLeaf9a4590Storage, public ArrayLeaf9a4590Size
{
    ~ArrayLeaf9a4590();  // compared: 0x9a4590
};

void FreeArrayLeaf9a4590(ArrayLeaf9a4590* array);
