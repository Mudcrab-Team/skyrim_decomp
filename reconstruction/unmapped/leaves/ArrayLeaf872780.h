// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf872780, ArrayLeaf872780Storage, ArrayLeaf872780Size, FreeArrayLeaf872780, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf872780Storage
{
    ~ArrayLeaf872780Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf872780Size
{
    ~ArrayLeaf872780Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf872780 : public ArrayLeaf872780Storage, public ArrayLeaf872780Size
{
    ~ArrayLeaf872780();  // compared: 0x872780
};

void FreeArrayLeaf872780(ArrayLeaf872780* array);
