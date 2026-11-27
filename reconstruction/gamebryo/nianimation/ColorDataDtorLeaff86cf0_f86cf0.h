// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
// volatile: the target updates this counter atomically.
extern volatile long gColorDataCountf86cf0;
extern void (*gColorKeyDestroyersf86cf0[])(void*);
class ColorDataBasef86cf0
{
public:
    virtual ~ColorDataBasef86cf0();
    std::uint8_t state[0x10];
};
class ColorDataDtorLeaff86cf0 : public ColorDataBasef86cf0
{
public:
    ColorDataDtorLeaff86cf0();
    ~ColorDataDtorLeaff86cf0() override;
    void* keys;
    std::int32_t type;
};
