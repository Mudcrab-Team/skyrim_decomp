// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf116c260, ArrayLeaf116c260Storage, ArrayLeaf116c260Size, FreeArrayLeaf116c260, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf116c260Storage
{
    ~ArrayLeaf116c260Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf116c260Size
{
    ~ArrayLeaf116c260Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf116c260 : public ArrayLeaf116c260Storage, public ArrayLeaf116c260Size
{
    ~ArrayLeaf116c260();  // compared: 0x116c260
};

void FreeArrayLeaf116c260(ArrayLeaf116c260* array);
