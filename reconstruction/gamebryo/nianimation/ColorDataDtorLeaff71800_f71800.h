// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
// volatile: the target updates this counter atomically.
extern volatile long gColorDataCountf71800;
extern void (*gColorKeyDestroyersf71800[])(void*);
class ColorDataBasef71800
{
public:
    virtual ~ColorDataBasef71800();
    std::uint8_t state[0x10];
};
class ColorDataDtorLeaff71800 : public ColorDataBasef71800
{
public:
    ~ColorDataDtorLeaff71800() override;
    void* keys;
    std::int32_t type;
};
