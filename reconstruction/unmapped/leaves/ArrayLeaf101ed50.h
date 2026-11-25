// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf101ed50, ArrayLeaf101ed50Storage, ArrayLeaf101ed50Size, FreeArrayLeaf101ed50, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf101ed50Storage
{
    ~ArrayLeaf101ed50Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf101ed50Size
{
    ~ArrayLeaf101ed50Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf101ed50 : public ArrayLeaf101ed50Storage, public ArrayLeaf101ed50Size
{
    ~ArrayLeaf101ed50();  // compared: 0x101ed50
};

void FreeArrayLeaf101ed50(ArrayLeaf101ed50* array);
