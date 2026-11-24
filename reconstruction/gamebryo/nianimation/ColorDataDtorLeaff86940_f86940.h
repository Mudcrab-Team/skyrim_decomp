// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
// volatile: the target updates this counter atomically.
extern volatile long gColorDataCountf86940;
extern void (*gColorKeyDestroyersf86940[])(void*);
class ColorDataBasef86940
{
public:
    virtual ~ColorDataBasef86940();
    std::uint8_t state[0x10];
};
class ColorDataDtorLeaff86940 : public ColorDataBasef86940
{
public:
    ~ColorDataDtorLeaff86940() override;
    void* keys;
    std::int32_t type;
};
