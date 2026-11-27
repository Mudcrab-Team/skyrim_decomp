// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf9861c0, ArrayLeaf9861c0Storage, ArrayLeaf9861c0Size, FreeArrayLeaf9861c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf9861c0Storage
{
    ~ArrayLeaf9861c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf9861c0Size
{
    ~ArrayLeaf9861c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf9861c0 : public ArrayLeaf9861c0Storage, public ArrayLeaf9861c0Size
{
    ~ArrayLeaf9861c0();  // compared: 0x9861c0
};

void FreeArrayLeaf9861c0(ArrayLeaf9861c0* array);
