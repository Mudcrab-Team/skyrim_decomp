// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf734eb0, ArrayLeaf734eb0Storage, ArrayLeaf734eb0Size, FreeArrayLeaf734eb0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf734eb0Storage
{
    ~ArrayLeaf734eb0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf734eb0Size
{
    ~ArrayLeaf734eb0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf734eb0 : public ArrayLeaf734eb0Storage, public ArrayLeaf734eb0Size
{
    ~ArrayLeaf734eb0();  // compared: 0x734eb0
};

void FreeArrayLeaf734eb0(ArrayLeaf734eb0* array);
