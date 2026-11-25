// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
struct FloatControllerNamef7d630
{
    ~FloatControllerNamef7d630() noexcept;
    void* data;
};
class FloatControllerBasef7d630
{
public:
    virtual ~FloatControllerBasef7d630() noexcept;
    std::uint8_t state[0x60];
};
class FloatControllerDtorLeaff7d630 : public FloatControllerBasef7d630
{
public:
    FloatControllerDtorLeaff7d630();
    ~FloatControllerDtorLeaff7d630() override;
    FloatControllerNamef7d630 name;
};
