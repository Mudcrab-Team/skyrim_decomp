// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafebda50, ArrayLeafebda50Storage, ArrayLeafebda50Size, FreeArrayLeafebda50, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafebda50Storage
{
    ~ArrayLeafebda50Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafebda50Size
{
    ~ArrayLeafebda50Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafebda50 : public ArrayLeafebda50Storage, public ArrayLeafebda50Size
{
    ~ArrayLeafebda50();  // compared: 0xebda50
};

void FreeArrayLeafebda50(ArrayLeafebda50* array);
