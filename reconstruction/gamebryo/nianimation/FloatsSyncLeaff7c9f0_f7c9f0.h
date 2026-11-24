// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController, SynchronizePoseInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct FloatsTypef7c9f0 { const char* name; const FloatsTypef7c9f0* parent; };
extern const FloatsTypef7c9f0 gFloatsTypef7c9f0;
class FloatsInterpolatorf7c9f0
{
public:
    virtual ~FloatsInterpolatorf7c9f0();
    virtual void DeleteThis();
    virtual const FloatsTypef7c9f0* GetType() const;
    void SetValue(float value);
};
struct FloatsDataf7c9f0 { float GetValue(int index); };
struct FloatsSyncLeaff7c9f0
{
    void SynchronizePoseInterpolator(FloatsInterpolatorf7c9f0* interpolator, std::uint16_t index);
    std::uint8_t unknown00[0x58];
    FloatsDataf7c9f0* data;
    int index;
};
