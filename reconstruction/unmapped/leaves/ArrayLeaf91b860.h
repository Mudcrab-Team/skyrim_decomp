// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf91b860, ArrayLeaf91b860Storage, ArrayLeaf91b860Size, FreeArrayLeaf91b860, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf91b860Storage
{
    ~ArrayLeaf91b860Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf91b860Size
{
    ~ArrayLeaf91b860Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf91b860 : public ArrayLeaf91b860Storage, public ArrayLeaf91b860Size
{
    ~ArrayLeaf91b860();  // compared: 0x91b860
};

void FreeArrayLeaf91b860(ArrayLeaf91b860* array);
