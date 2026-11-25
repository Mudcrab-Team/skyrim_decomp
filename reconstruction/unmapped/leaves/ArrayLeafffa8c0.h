// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafffa8c0, ArrayLeafffa8c0Storage, ArrayLeafffa8c0Size, FreeArrayLeafffa8c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafffa8c0Storage
{
    ~ArrayLeafffa8c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafffa8c0Size
{
    ~ArrayLeafffa8c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafffa8c0 : public ArrayLeafffa8c0Storage, public ArrayLeafffa8c0Size
{
    ~ArrayLeafffa8c0();  // compared: 0xffa8c0
};

void FreeArrayLeafffa8c0(ArrayLeafffa8c0* array);
