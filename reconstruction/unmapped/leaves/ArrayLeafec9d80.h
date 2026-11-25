// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafec9d80, ArrayLeafec9d80Storage, ArrayLeafec9d80Size, FreeArrayLeafec9d80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafec9d80Storage
{
    ~ArrayLeafec9d80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafec9d80Size
{
    ~ArrayLeafec9d80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafec9d80 : public ArrayLeafec9d80Storage, public ArrayLeafec9d80Size
{
    ~ArrayLeafec9d80();  // compared: 0xec9d80
};

void FreeArrayLeafec9d80(ArrayLeafec9d80* array);
