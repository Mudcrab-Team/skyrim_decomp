// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysColorModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct ColorModifierNamefaa4e0
{
    explicit ColorModifierNamefaa4e0(const char* value);
    ~ColorModifierNamefaa4e0();
    void* data;
};
struct ColorModifierReffaa4e0
{
    ColorModifierReffaa4e0();
    ~ColorModifierReffaa4e0();
    void* value;
};
class ColorModifierBasefaa4e0
{
public:
    ColorModifierBasefaa4e0(const ColorModifierNamefaa4e0& name, std::uint32_t order);
    virtual ~ColorModifierBasefaa4e0();
    std::uint8_t state[0x28];
};
class ColorModifierCtorLeaffaa4e0 : public ColorModifierBasefaa4e0
{
public:
    ColorModifierCtorLeaffaa4e0(const char* name, void* data);
    void SetColorData(void* data);
    ColorModifierReffaa4e0 data;
    std::uint64_t timeRange;
};
