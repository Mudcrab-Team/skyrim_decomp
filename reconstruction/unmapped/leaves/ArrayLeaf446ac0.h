// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// ArrayLeaf446ac0, ArrayLeaf446ac0Storage, ArrayLeaf446ac0Size, FreeArrayLeaf446ac0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf446ac0Storage
{
    ~ArrayLeaf446ac0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf446ac0Size
{
    ~ArrayLeaf446ac0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf446ac0 : public ArrayLeaf446ac0Storage, public ArrayLeaf446ac0Size
{
    ~ArrayLeaf446ac0();  // compared: 0x446ac0
};

void FreeArrayLeaf446ac0(ArrayLeaf446ac0* array);
