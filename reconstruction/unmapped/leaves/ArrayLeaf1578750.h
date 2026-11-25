// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1578750, ArrayLeaf1578750Storage, ArrayLeaf1578750Size, FreeArrayLeaf1578750, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1578750Storage
{
    ~ArrayLeaf1578750Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1578750Size
{
    ~ArrayLeaf1578750Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1578750 : public ArrayLeaf1578750Storage, public ArrayLeaf1578750Size
{
    ~ArrayLeaf1578750();  // compared: 0x1578750
};

void FreeArrayLeaf1578750(ArrayLeaf1578750* array);
