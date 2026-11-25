// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1068d60, ArrayLeaf1068d60Storage, ArrayLeaf1068d60Size, FreeArrayLeaf1068d60, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1068d60Storage
{
    ~ArrayLeaf1068d60Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1068d60Size
{
    ~ArrayLeaf1068d60Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1068d60 : public ArrayLeaf1068d60Storage, public ArrayLeaf1068d60Size
{
    ~ArrayLeaf1068d60();  // compared: 0x1068d60
};

void FreeArrayLeaf1068d60(ArrayLeaf1068d60* array);
