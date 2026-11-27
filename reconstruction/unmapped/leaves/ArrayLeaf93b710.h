// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf93b710, ArrayLeaf93b710Storage, ArrayLeaf93b710Size, FreeArrayLeaf93b710, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf93b710Storage
{
    ~ArrayLeaf93b710Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf93b710Size
{
    ~ArrayLeaf93b710Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf93b710 : public ArrayLeaf93b710Storage, public ArrayLeaf93b710Size
{
    ~ArrayLeaf93b710();  // compared: 0x93b710
};

void FreeArrayLeaf93b710(ArrayLeaf93b710* array);
