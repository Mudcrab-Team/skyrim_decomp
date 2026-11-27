// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf804840, ArrayLeaf804840Storage, ArrayLeaf804840Size, FreeArrayLeaf804840, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf804840Storage
{
    ~ArrayLeaf804840Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf804840Size
{
    ~ArrayLeaf804840Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf804840 : public ArrayLeaf804840Storage, public ArrayLeaf804840Size
{
    ~ArrayLeaf804840();  // compared: 0x804840
};

void FreeArrayLeaf804840(ArrayLeaf804840* array);
