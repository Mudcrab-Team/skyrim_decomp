// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6c7250, ArrayLeaf6c7250Storage, ArrayLeaf6c7250Size, FreeArrayLeaf6c7250, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6c7250Storage
{
    ~ArrayLeaf6c7250Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6c7250Size
{
    ~ArrayLeaf6c7250Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6c7250 : public ArrayLeaf6c7250Storage, public ArrayLeaf6c7250Size
{
    ~ArrayLeaf6c7250();  // compared: 0x6c7250
};

void FreeArrayLeaf6c7250(ArrayLeaf6c7250* array);
