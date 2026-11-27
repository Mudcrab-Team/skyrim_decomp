// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorExtraDataController, SynchronizePoseInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct ColorTypef7c280 { const char* name; const ColorTypef7c280* parent; };
extern const ColorTypef7c280 gColorTypef7c280;
struct ColorValuef7c280 { std::uint32_t channels[4]; };
class ColorInterpolatorf7c280
{
public:
    virtual ~ColorInterpolatorf7c280();
    virtual void DeleteThis();
    virtual const ColorTypef7c280* GetType() const;
    void SetValue(ColorValuef7c280 value);
};
struct ColorDataf7c280 { std::uint8_t unknown00[0x18]; ColorValuef7c280 value; };
struct ColorSyncLeaff7c280
{
    void SynchronizePoseInterpolator(ColorInterpolatorf7c280* interpolator, std::uint16_t index);
    std::uint8_t unknown00[0x58];
    ColorDataf7c280* data;
};
