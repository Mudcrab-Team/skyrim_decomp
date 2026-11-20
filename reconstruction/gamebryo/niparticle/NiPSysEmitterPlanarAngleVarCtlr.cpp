// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfaf2c0 NiPSysEmitterPlanarAngleVarCtlr::GetTargetValue
// 0xfaf2d0 NiPSysEmitterPlanarAngleVarCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterPlanarAngleVarCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterPlanarAngleVarCtlr::GetTargetValue(float& value) const
{
    value = modifier->planarAngleVariance;
}

void NiPSysEmitterPlanarAngleVarCtlr::SetTargetValue(float value)
{
    modifier->planarAngleVariance = value;
}
