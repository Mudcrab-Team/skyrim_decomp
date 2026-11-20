// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfadec0 NiPSysEmitterDeclinationCtlr::GetTargetValue
// 0xfaded0 NiPSysEmitterDeclinationCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterDeclinationCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterDeclinationCtlr::GetTargetValue(float& value) const
{
    value = modifier->declination;
}

void NiPSysEmitterDeclinationCtlr::SetTargetValue(float value)
{
    modifier->declination = value;
}
