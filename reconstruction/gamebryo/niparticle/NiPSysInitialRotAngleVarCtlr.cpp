// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb22c0 NiPSysInitialRotAngleVarCtlr::GetTargetValue
// 0xfb22d0 NiPSysInitialRotAngleVarCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysInitialRotAngleVarCtlr.h"
#include "gamebryo/niparticle/NiPSysRotationModifierFields.h"

void NiPSysInitialRotAngleVarCtlr::GetTargetValue(float& value) const
{
    value = modifier->initialRotationAngleVariance;
}

void NiPSysInitialRotAngleVarCtlr::SetTargetValue(float value)
{
    modifier->initialRotationAngleVariance = value;
}
