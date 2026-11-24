// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf92e330, ArrayLeaf92e330Storage, ArrayLeaf92e330Size, FreeArrayLeaf92e330, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf92e330Storage
{
    ~ArrayLeaf92e330Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf92e330Size
{
    ~ArrayLeaf92e330Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf92e330 : public ArrayLeaf92e330Storage, public ArrayLeaf92e330Size
{
    ~ArrayLeaf92e330();  // compared: 0x92e330
};

void FreeArrayLeaf92e330(ArrayLeaf92e330* array);
