// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767370, ArrayLeaf767370Storage, ArrayLeaf767370Size, FreeArrayLeaf767370, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767370Storage
{
    ~ArrayLeaf767370Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767370Size
{
    ~ArrayLeaf767370Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767370 : public ArrayLeaf767370Storage, public ArrayLeaf767370Size
{
    ~ArrayLeaf767370();  // compared: 0x767370
};

void FreeArrayLeaf767370(ArrayLeaf767370* array);
