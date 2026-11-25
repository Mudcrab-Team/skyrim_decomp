// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf62bac0, ArrayLeaf62bac0Storage, ArrayLeaf62bac0Size, FreeArrayLeaf62bac0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf62bac0Storage
{
    ~ArrayLeaf62bac0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf62bac0Size
{
    ~ArrayLeaf62bac0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf62bac0 : public ArrayLeaf62bac0Storage, public ArrayLeaf62bac0Size
{
    ~ArrayLeaf62bac0();  // compared: 0x62bac0
};

void FreeArrayLeaf62bac0(ArrayLeaf62bac0* array);
