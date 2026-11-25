// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1211d80, ArrayLeaf1211d80Storage, ArrayLeaf1211d80Size, FreeArrayLeaf1211d80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1211d80Storage
{
    ~ArrayLeaf1211d80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1211d80Size
{
    ~ArrayLeaf1211d80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1211d80 : public ArrayLeaf1211d80Storage, public ArrayLeaf1211d80Size
{
    ~ArrayLeaf1211d80();  // compared: 0x1211d80
};

void FreeArrayLeaf1211d80(ArrayLeaf1211d80* array);
