// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf874420, ArrayLeaf874420Storage, ArrayLeaf874420Size, FreeArrayLeaf874420, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf874420Storage
{
    ~ArrayLeaf874420Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf874420Size
{
    ~ArrayLeaf874420Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf874420 : public ArrayLeaf874420Storage, public ArrayLeaf874420Size
{
    ~ArrayLeaf874420();  // compared: 0x874420
};

void FreeArrayLeaf874420(ArrayLeaf874420* array);
