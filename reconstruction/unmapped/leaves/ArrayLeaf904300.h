// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf904300, ArrayLeaf904300Storage, ArrayLeaf904300Size, FreeArrayLeaf904300, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf904300Storage
{
    ~ArrayLeaf904300Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf904300Size
{
    ~ArrayLeaf904300Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf904300 : public ArrayLeaf904300Storage, public ArrayLeaf904300Size
{
    ~ArrayLeaf904300();  // compared: 0x904300
};

void FreeArrayLeaf904300(ArrayLeaf904300* array);
