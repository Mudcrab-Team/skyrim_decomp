// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1250280, ArrayLeaf1250280Storage, ArrayLeaf1250280Size, FreeArrayLeaf1250280, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1250280Storage
{
    ~ArrayLeaf1250280Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1250280Size
{
    ~ArrayLeaf1250280Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1250280 : public ArrayLeaf1250280Storage, public ArrayLeaf1250280Size
{
    ~ArrayLeaf1250280();  // compared: 0x1250280
};

void FreeArrayLeaf1250280(ArrayLeaf1250280* array);
