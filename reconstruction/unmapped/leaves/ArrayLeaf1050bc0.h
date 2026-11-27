// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1050bc0, ArrayLeaf1050bc0Storage, ArrayLeaf1050bc0Size, FreeArrayLeaf1050bc0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1050bc0Storage
{
    ~ArrayLeaf1050bc0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1050bc0Size
{
    ~ArrayLeaf1050bc0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1050bc0 : public ArrayLeaf1050bc0Storage, public ArrayLeaf1050bc0Size
{
    ~ArrayLeaf1050bc0();  // compared: 0x1050bc0
};

void FreeArrayLeaf1050bc0(ArrayLeaf1050bc0* array);
