// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBoolData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets and element size observed on the target.
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
// volatile: the target updates this counter atomically.
extern volatile long gArrayRefCountf75180;
struct ArrayRefElementf75180
{
    ~ArrayRefElementf75180();
    std::uint32_t state[2];
};
class ArrayRefBasef75180
{
public:
    virtual ~ArrayRefBasef75180();
    std::uint8_t state[0x10];
};
class ArrayRefDtorLeaff75180 : public ArrayRefBasef75180
{
public:
    ~ArrayRefDtorLeaff75180() override;
    ArrayRefElementf75180* elements;
};
