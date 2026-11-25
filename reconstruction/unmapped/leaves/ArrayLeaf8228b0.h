// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf8228b0, ArrayLeaf8228b0Storage, ArrayLeaf8228b0Size, FreeArrayLeaf8228b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf8228b0Storage
{
    ~ArrayLeaf8228b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf8228b0Size
{
    ~ArrayLeaf8228b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf8228b0 : public ArrayLeaf8228b0Storage, public ArrayLeaf8228b0Size
{
    ~ArrayLeaf8228b0();  // compared: 0x8228b0
};

void FreeArrayLeaf8228b0(ArrayLeaf8228b0* array);
