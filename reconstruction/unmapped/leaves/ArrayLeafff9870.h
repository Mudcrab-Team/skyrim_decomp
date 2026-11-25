// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeafff9870, ArrayLeafff9870Storage, ArrayLeafff9870Size, FreeArrayLeafff9870, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeafff9870Storage
{
    ~ArrayLeafff9870Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeafff9870Size
{
    ~ArrayLeafff9870Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeafff9870 : public ArrayLeafff9870Storage, public ArrayLeafff9870Size
{
    ~ArrayLeafff9870();  // compared: 0xff9870
};

void FreeArrayLeafff9870(ArrayLeafff9870* array);
