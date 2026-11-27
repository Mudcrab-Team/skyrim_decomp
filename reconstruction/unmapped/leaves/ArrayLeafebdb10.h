// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafebdb10, ArrayLeafebdb10Storage, ArrayLeafebdb10Size, FreeArrayLeafebdb10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafebdb10Storage
{
    ~ArrayLeafebdb10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafebdb10Size
{
    ~ArrayLeafebdb10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafebdb10 : public ArrayLeafebdb10Storage, public ArrayLeafebdb10Size
{
    ~ArrayLeafebdb10();  // compared: 0xebdb10
};

void FreeArrayLeafebdb10(ArrayLeafebdb10* array);
