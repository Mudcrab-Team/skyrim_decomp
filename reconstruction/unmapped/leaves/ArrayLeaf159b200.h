// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf159b200, ArrayLeaf159b200Storage, ArrayLeaf159b200Size, FreeArrayLeaf159b200, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf159b200Storage
{
    ~ArrayLeaf159b200Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf159b200Size
{
    ~ArrayLeaf159b200Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf159b200 : public ArrayLeaf159b200Storage, public ArrayLeaf159b200Size
{
    ~ArrayLeaf159b200();  // compared: 0x159b200
};

void FreeArrayLeaf159b200(ArrayLeaf159b200* array);
