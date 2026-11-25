// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offsets observed on the target
#pragma once
#include <cstdint>

struct FloatControllerName
{
    explicit FloatControllerName(const char* value);
    ~FloatControllerName();
    void* data;
};
class FloatControllerCtorBase
{
public:
    FloatControllerCtorBase();
    virtual ~FloatControllerCtorBase();
    std::uint8_t state[0x58];
};
class FloatControllerCtorLeaff7cbd0 : public FloatControllerCtorBase
{
public:
    FloatControllerCtorLeaff7cbd0();
    std::int32_t index;
    FloatControllerName name;
};
