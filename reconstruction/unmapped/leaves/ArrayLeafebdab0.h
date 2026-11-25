// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafebdab0, ArrayLeafebdab0Storage, ArrayLeafebdab0Size, FreeArrayLeafebdab0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafebdab0Storage
{
    ~ArrayLeafebdab0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafebdab0Size
{
    ~ArrayLeafebdab0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafebdab0 : public ArrayLeafebdab0Storage, public ArrayLeafebdab0Size
{
    ~ArrayLeafebdab0();  // compared: 0xebdab0
};

void FreeArrayLeafebdab0(ArrayLeafebdab0* array);
