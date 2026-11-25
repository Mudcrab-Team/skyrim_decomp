// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf116c320, ArrayLeaf116c320Storage, ArrayLeaf116c320Size, FreeArrayLeaf116c320, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf116c320Storage
{
    ~ArrayLeaf116c320Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf116c320Size
{
    ~ArrayLeaf116c320Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf116c320 : public ArrayLeaf116c320Storage, public ArrayLeaf116c320Size
{
    ~ArrayLeaf116c320();  // compared: 0x116c320
};

void FreeArrayLeaf116c320(ArrayLeaf116c320* array);
