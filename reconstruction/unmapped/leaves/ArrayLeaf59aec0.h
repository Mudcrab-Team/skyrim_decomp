// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf59aec0, ArrayLeaf59aec0Storage, ArrayLeaf59aec0Size, FreeArrayLeaf59aec0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf59aec0Storage
{
    ~ArrayLeaf59aec0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf59aec0Size
{
    ~ArrayLeaf59aec0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf59aec0 : public ArrayLeaf59aec0Storage, public ArrayLeaf59aec0Size
{
    ~ArrayLeaf59aec0();  // compared: 0x59aec0
};

void FreeArrayLeaf59aec0(ArrayLeaf59aec0* array);
