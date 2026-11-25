// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafa6bd90, ArrayLeafa6bd90Storage, ArrayLeafa6bd90Size, FreeArrayLeafa6bd90, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafa6bd90Storage
{
    ~ArrayLeafa6bd90Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafa6bd90Size
{
    ~ArrayLeafa6bd90Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafa6bd90 : public ArrayLeafa6bd90Storage, public ArrayLeafa6bd90Size
{
    ~ArrayLeafa6bd90();  // compared: 0xa6bd90
};

void FreeArrayLeafa6bd90(ArrayLeafa6bd90* array);
