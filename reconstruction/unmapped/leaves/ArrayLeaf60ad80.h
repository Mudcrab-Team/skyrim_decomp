// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf60ad80, ArrayLeaf60ad80Storage, ArrayLeaf60ad80Size, FreeArrayLeaf60ad80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf60ad80Storage
{
    ~ArrayLeaf60ad80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf60ad80Size
{
    ~ArrayLeaf60ad80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf60ad80 : public ArrayLeaf60ad80Storage, public ArrayLeaf60ad80Size
{
    ~ArrayLeaf60ad80();  // compared: 0x60ad80
};

void FreeArrayLeaf60ad80(ArrayLeaf60ad80* array);
