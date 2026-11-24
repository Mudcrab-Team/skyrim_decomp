// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767c10, ArrayLeaf767c10Storage, ArrayLeaf767c10Size, FreeArrayLeaf767c10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767c10Storage
{
    ~ArrayLeaf767c10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767c10Size
{
    ~ArrayLeaf767c10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767c10 : public ArrayLeaf767c10Storage, public ArrayLeaf767c10Size
{
    ~ArrayLeaf767c10();  // compared: 0x767c10
};

void FreeArrayLeaf767c10(ArrayLeaf767c10* array);
