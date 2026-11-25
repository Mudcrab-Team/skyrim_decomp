// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf91bbc0, ArrayLeaf91bbc0Storage, ArrayLeaf91bbc0Size, FreeArrayLeaf91bbc0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf91bbc0Storage
{
    ~ArrayLeaf91bbc0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf91bbc0Size
{
    ~ArrayLeaf91bbc0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf91bbc0 : public ArrayLeaf91bbc0Storage, public ArrayLeaf91bbc0Size
{
    ~ArrayLeaf91bbc0();  // compared: 0x91bbc0
};

void FreeArrayLeaf91bbc0(ArrayLeaf91bbc0* array);
