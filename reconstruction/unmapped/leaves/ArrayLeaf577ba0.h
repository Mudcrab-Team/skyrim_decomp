// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf577ba0, ArrayLeaf577ba0Storage, ArrayLeaf577ba0Size, FreeArrayLeaf577ba0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf577ba0Storage
{
    ~ArrayLeaf577ba0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf577ba0Size
{
    ~ArrayLeaf577ba0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf577ba0 : public ArrayLeaf577ba0Storage, public ArrayLeaf577ba0Size
{
    ~ArrayLeaf577ba0();  // compared: 0x577ba0
};

void FreeArrayLeaf577ba0(ArrayLeaf577ba0* array);
