// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf857eb0, ArrayLeaf857eb0Storage, ArrayLeaf857eb0Size, FreeArrayLeaf857eb0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf857eb0Storage
{
    ~ArrayLeaf857eb0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf857eb0Size
{
    ~ArrayLeaf857eb0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf857eb0 : public ArrayLeaf857eb0Storage, public ArrayLeaf857eb0Size
{
    ~ArrayLeaf857eb0();  // compared: 0x857eb0
};

void FreeArrayLeaf857eb0(ArrayLeaf857eb0* array);
