// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1007910, ArrayLeaf1007910Storage, ArrayLeaf1007910Size, FreeArrayLeaf1007910, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1007910Storage
{
    ~ArrayLeaf1007910Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1007910Size
{
    ~ArrayLeaf1007910Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1007910 : public ArrayLeaf1007910Storage, public ArrayLeaf1007910Size
{
    ~ArrayLeaf1007910();  // compared: 0x1007910
};

void FreeArrayLeaf1007910(ArrayLeaf1007910* array);
