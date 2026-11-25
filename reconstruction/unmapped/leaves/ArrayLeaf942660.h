// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf942660, ArrayLeaf942660Storage, ArrayLeaf942660Size, FreeArrayLeaf942660, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf942660Storage
{
    ~ArrayLeaf942660Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf942660Size
{
    ~ArrayLeaf942660Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf942660 : public ArrayLeaf942660Storage, public ArrayLeaf942660Size
{
    ~ArrayLeaf942660();  // compared: 0x942660
};

void FreeArrayLeaf942660(ArrayLeaf942660* array);
