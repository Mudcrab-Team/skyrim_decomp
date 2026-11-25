// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf7679d0, ArrayLeaf7679d0Storage, ArrayLeaf7679d0Size, FreeArrayLeaf7679d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf7679d0Storage
{
    ~ArrayLeaf7679d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf7679d0Size
{
    ~ArrayLeaf7679d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf7679d0 : public ArrayLeaf7679d0Storage, public ArrayLeaf7679d0Size
{
    ~ArrayLeaf7679d0();  // compared: 0x7679d0
};

void FreeArrayLeaf7679d0(ArrayLeaf7679d0* array);
