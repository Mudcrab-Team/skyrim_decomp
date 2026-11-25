// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf4bffe0, ArrayLeaf4bffe0Storage, ArrayLeaf4bffe0Size, FreeArrayLeaf4bffe0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf4bffe0Storage
{
    ~ArrayLeaf4bffe0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf4bffe0Size
{
    ~ArrayLeaf4bffe0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf4bffe0 : public ArrayLeaf4bffe0Storage, public ArrayLeaf4bffe0Size
{
    ~ArrayLeaf4bffe0();  // compared: 0x4bffe0
};

void FreeArrayLeaf4bffe0(ArrayLeaf4bffe0* array);
