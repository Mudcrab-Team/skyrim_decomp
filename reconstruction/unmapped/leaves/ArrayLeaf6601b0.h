// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf6601b0, ArrayLeaf6601b0Storage, ArrayLeaf6601b0Size, FreeArrayLeaf6601b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf6601b0Storage
{
    ~ArrayLeaf6601b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf6601b0Size
{
    ~ArrayLeaf6601b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf6601b0 : public ArrayLeaf6601b0Storage, public ArrayLeaf6601b0Size
{
    ~ArrayLeaf6601b0();  // compared: 0x6601b0
};

void FreeArrayLeaf6601b0(ArrayLeaf6601b0* array);
