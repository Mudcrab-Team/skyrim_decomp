// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysPositionModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); call pattern observed on the target
#pragma once
#include <cstdint>

struct PositionName
{
    explicit PositionName(const char* text);
    ~PositionName();
    void* value;
};
class PositionModifierBase
{
public:
    PositionModifierBase(const PositionName& name, std::uint32_t order);
    virtual ~PositionModifierBase();
    std::uint8_t state[0x28];
};
class PositionCtorLeaffb7460 : public PositionModifierBase
{
public:
    explicit PositionCtorLeaffb7460(const char* name);
};
