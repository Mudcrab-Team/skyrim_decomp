// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf643ed0, ArrayLeaf643ed0Storage, ArrayLeaf643ed0Size, FreeArrayLeaf643ed0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf643ed0Storage
{
    ~ArrayLeaf643ed0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf643ed0Size
{
    ~ArrayLeaf643ed0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf643ed0 : public ArrayLeaf643ed0Storage, public ArrayLeaf643ed0Size
{
    ~ArrayLeaf643ed0();  // compared: 0x643ed0
};

void FreeArrayLeaf643ed0(ArrayLeaf643ed0* array);
