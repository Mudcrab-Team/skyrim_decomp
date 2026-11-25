// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafd02f10, ArrayLeafd02f10Storage, ArrayLeafd02f10Size, FreeArrayLeafd02f10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafd02f10Storage
{
    ~ArrayLeafd02f10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafd02f10Size
{
    ~ArrayLeafd02f10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafd02f10 : public ArrayLeafd02f10Storage, public ArrayLeafd02f10Size
{
    ~ArrayLeafd02f10();  // compared: 0xd02f10
};

void FreeArrayLeafd02f10(ArrayLeafd02f10* array);
