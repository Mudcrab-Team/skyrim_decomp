// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf53cdc0, ArrayLeaf53cdc0Storage, ArrayLeaf53cdc0Size, FreeArrayLeaf53cdc0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf53cdc0Storage
{
    ~ArrayLeaf53cdc0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf53cdc0Size
{
    ~ArrayLeaf53cdc0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf53cdc0 : public ArrayLeaf53cdc0Storage, public ArrayLeaf53cdc0Size
{
    ~ArrayLeaf53cdc0();  // compared: 0x53cdc0
};

void FreeArrayLeaf53cdc0(ArrayLeaf53cdc0* array);
