// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4e74b0, ArrayLeaf4e74b0Storage, ArrayLeaf4e74b0Size, FreeArrayLeaf4e74b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4e74b0Storage
{
    ~ArrayLeaf4e74b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4e74b0Size
{
    ~ArrayLeaf4e74b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4e74b0 : public ArrayLeaf4e74b0Storage, public ArrayLeaf4e74b0Size
{
    ~ArrayLeaf4e74b0();  // compared: 0x4e74b0
};

void FreeArrayLeaf4e74b0(ArrayLeaf4e74b0* array);
