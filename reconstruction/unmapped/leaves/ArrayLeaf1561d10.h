// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1561d10, ArrayLeaf1561d10Storage, ArrayLeaf1561d10Size, FreeArrayLeaf1561d10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1561d10Storage
{
    ~ArrayLeaf1561d10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1561d10Size
{
    ~ArrayLeaf1561d10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1561d10 : public ArrayLeaf1561d10Storage, public ArrayLeaf1561d10Size
{
    ~ArrayLeaf1561d10();  // compared: 0x1561d10
};

void FreeArrayLeaf1561d10(ArrayLeaf1561d10* array);
