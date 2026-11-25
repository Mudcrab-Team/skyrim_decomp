// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf779ae0, ArrayLeaf779ae0Storage, ArrayLeaf779ae0Size, FreeArrayLeaf779ae0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf779ae0Storage
{
    ~ArrayLeaf779ae0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf779ae0Size
{
    ~ArrayLeaf779ae0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf779ae0 : public ArrayLeaf779ae0Storage, public ArrayLeaf779ae0Size
{
    ~ArrayLeaf779ae0();  // compared: 0x779ae0
};

void FreeArrayLeaf779ae0(ArrayLeaf779ae0* array);
