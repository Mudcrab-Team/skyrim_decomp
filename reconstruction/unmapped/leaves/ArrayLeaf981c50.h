// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf981c50, ArrayLeaf981c50Storage, ArrayLeaf981c50Size, FreeArrayLeaf981c50, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf981c50Storage
{
    ~ArrayLeaf981c50Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf981c50Size
{
    ~ArrayLeaf981c50Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf981c50 : public ArrayLeaf981c50Storage, public ArrayLeaf981c50Size
{
    ~ArrayLeaf981c50();  // compared: 0x981c50
};

void FreeArrayLeaf981c50(ArrayLeaf981c50* array);
