// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf1250160, ArrayLeaf1250160Storage, ArrayLeaf1250160Size, FreeArrayLeaf1250160, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1250160Storage
{
    ~ArrayLeaf1250160Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1250160Size
{
    ~ArrayLeaf1250160Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1250160 : public ArrayLeaf1250160Storage, public ArrayLeaf1250160Size
{
    ~ArrayLeaf1250160();  // compared: 0x1250160
};

void FreeArrayLeaf1250160(ArrayLeaf1250160* array);
