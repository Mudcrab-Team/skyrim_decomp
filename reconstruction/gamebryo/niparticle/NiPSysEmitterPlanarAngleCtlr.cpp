// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfaeec0 NiPSysEmitterPlanarAngleCtlr::GetTargetValue
// 0xfaeed0 NiPSysEmitterPlanarAngleCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterPlanarAngleCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterPlanarAngleCtlr::GetTargetValue(float& value) const
{
    value = modifier->planarAngle;
}

void NiPSysEmitterPlanarAngleCtlr::SetTargetValue(float value)
{
    modifier->planarAngle = value;
}
