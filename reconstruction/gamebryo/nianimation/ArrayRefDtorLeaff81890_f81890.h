// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiMorphData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets and element size observed on the target.
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
// volatile: the target updates this counter atomically.
extern volatile long gArrayRefCountf81890;
struct ArrayRefElementf81890
{
    ~ArrayRefElementf81890();
    std::uint32_t state[8];
};
class ArrayRefBasef81890
{
public:
    virtual ~ArrayRefBasef81890();
    std::uint8_t state[0x10];
};
class ArrayRefDtorLeaff81890 : public ArrayRefBasef81890
{
public:
    ~ArrayRefDtorLeaff81890() override;
    ArrayRefElementf81890* elements;
};
