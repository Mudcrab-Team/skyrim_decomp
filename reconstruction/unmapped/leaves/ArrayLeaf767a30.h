// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767a30, ArrayLeaf767a30Storage, ArrayLeaf767a30Size, FreeArrayLeaf767a30, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767a30Storage
{
    ~ArrayLeaf767a30Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767a30Size
{
    ~ArrayLeaf767a30Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767a30 : public ArrayLeaf767a30Storage, public ArrayLeaf767a30Size
{
    ~ArrayLeaf767a30();  // compared: 0x767a30
};

void FreeArrayLeaf767a30(ArrayLeaf767a30* array);
