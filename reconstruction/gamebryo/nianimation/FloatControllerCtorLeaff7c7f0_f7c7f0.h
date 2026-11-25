// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct FixedNamef7c7f0;
struct FloatNamef7c7f0
{
    explicit FloatNamef7c7f0(const char* value);
    ~FloatNamef7c7f0();
    void* data;
};
class FloatCtorBasef7c7f0
{
public:
    explicit FloatCtorBasef7c7f0(const FixedNamef7c7f0& name);
    virtual ~FloatCtorBasef7c7f0();
    std::uint8_t state[0x58];
};
class FloatControllerCtorLeaff7c7f0 : public FloatCtorBasef7c7f0
{
public:
    FloatControllerCtorLeaff7c7f0(const FixedNamef7c7f0& name, int indexValue);
    std::int32_t index;
    FloatNamef7c7f0 name;
};
