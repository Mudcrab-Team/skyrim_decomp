// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf779b40, ArrayLeaf779b40Storage, ArrayLeaf779b40Size, FreeArrayLeaf779b40, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf779b40Storage
{
    ~ArrayLeaf779b40Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf779b40Size
{
    ~ArrayLeaf779b40Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf779b40 : public ArrayLeaf779b40Storage, public ArrayLeaf779b40Size
{
    ~ArrayLeaf779b40();  // compared: 0x779b40
};

void FreeArrayLeaf779b40(ArrayLeaf779b40* array);
