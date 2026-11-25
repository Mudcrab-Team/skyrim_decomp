// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaffe41d0, ArrayLeaffe41d0Storage, ArrayLeaffe41d0Size, FreeArrayLeaffe41d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaffe41d0Storage
{
    ~ArrayLeaffe41d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaffe41d0Size
{
    ~ArrayLeaffe41d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaffe41d0 : public ArrayLeaffe41d0Storage, public ArrayLeaffe41d0Size
{
    ~ArrayLeaffe41d0();  // compared: 0xfe41d0
};

void FreeArrayLeaffe41d0(ArrayLeaffe41d0* array);
