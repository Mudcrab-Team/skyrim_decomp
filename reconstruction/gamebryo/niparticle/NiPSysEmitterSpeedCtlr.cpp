// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfaf6c0 NiPSysEmitterSpeedCtlr::GetTargetValue
// 0xfaf6d0 NiPSysEmitterSpeedCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterSpeedCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterSpeedCtlr::GetTargetValue(float& value) const
{
    value = modifier->speed;
}

void NiPSysEmitterSpeedCtlr::SetTargetValue(float value)
{
    modifier->speed = value;
}
