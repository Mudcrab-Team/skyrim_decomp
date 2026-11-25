// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafffe0c0, ArrayLeafffe0c0Storage, ArrayLeafffe0c0Size, FreeArrayLeafffe0c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafffe0c0Storage
{
    ~ArrayLeafffe0c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafffe0c0Size
{
    ~ArrayLeafffe0c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafffe0c0 : public ArrayLeafffe0c0Storage, public ArrayLeafffe0c0Size
{
    ~ArrayLeafffe0c0();  // compared: 0xffe0c0
};

void FreeArrayLeafffe0c0(ArrayLeafffe0c0* array);
