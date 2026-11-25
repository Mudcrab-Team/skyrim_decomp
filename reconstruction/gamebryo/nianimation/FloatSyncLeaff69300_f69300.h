// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatExtraDataController, SynchronizePoseInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct FloatTypef69300 { const char* name; const FloatTypef69300* parent; };
extern const FloatTypef69300 gFloatTypef69300;
class FloatInterpolatorf69300
{
public:
    virtual ~FloatInterpolatorf69300();
    virtual void DeleteThis();
    virtual const FloatTypef69300* GetType() const;
    void SetValue(float value);
};
struct FloatDataf69300 { std::uint8_t unknown00[0x18]; float value; };
struct FloatSyncLeaff69300
{
    void SynchronizePoseInterpolator(FloatInterpolatorf69300* interpolator, std::uint16_t index);
    std::uint8_t unknown00[0x58];
    FloatDataf69300* data;
};
