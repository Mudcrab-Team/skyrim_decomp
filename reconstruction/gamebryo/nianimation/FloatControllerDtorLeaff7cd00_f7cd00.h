// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
struct FloatControllerNamef7cd00
{
    ~FloatControllerNamef7cd00() noexcept;
    void* data;
};
class FloatControllerBasef7cd00
{
public:
    virtual ~FloatControllerBasef7cd00() noexcept;
    std::uint8_t state[0x60];
};
class FloatControllerDtorLeaff7cd00 : public FloatControllerBasef7cd00
{
public:
    FloatControllerDtorLeaff7cd00();
    ~FloatControllerDtorLeaff7cd00() override;
    FloatControllerNamef7cd00 name;
};
