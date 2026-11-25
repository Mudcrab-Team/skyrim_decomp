// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf585720, ArrayLeaf585720Storage, ArrayLeaf585720Size, FreeArrayLeaf585720, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf585720Storage
{
    ~ArrayLeaf585720Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf585720Size
{
    ~ArrayLeaf585720Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf585720 : public ArrayLeaf585720Storage, public ArrayLeaf585720Size
{
    ~ArrayLeaf585720();  // compared: 0x585720
};

void FreeArrayLeaf585720(ArrayLeaf585720* array);
