// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf767850, ArrayLeaf767850Storage, ArrayLeaf767850Size, FreeArrayLeaf767850, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf767850Storage
{
    ~ArrayLeaf767850Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf767850Size
{
    ~ArrayLeaf767850Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf767850 : public ArrayLeaf767850Storage, public ArrayLeaf767850Size
{
    ~ArrayLeaf767850();  // compared: 0x767850
};

void FreeArrayLeaf767850(ArrayLeaf767850* array);
