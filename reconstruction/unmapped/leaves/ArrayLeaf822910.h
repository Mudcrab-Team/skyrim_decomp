// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf822910, ArrayLeaf822910Storage, ArrayLeaf822910Size, FreeArrayLeaf822910, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf822910Storage
{
    ~ArrayLeaf822910Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf822910Size
{
    ~ArrayLeaf822910Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf822910 : public ArrayLeaf822910Storage, public ArrayLeaf822910Size
{
    ~ArrayLeaf822910();  // compared: 0x822910
};

void FreeArrayLeaf822910(ArrayLeaf822910* array);
