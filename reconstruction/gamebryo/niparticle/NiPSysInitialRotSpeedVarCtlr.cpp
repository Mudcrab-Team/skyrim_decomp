// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb2ac0 NiPSysInitialRotSpeedVarCtlr::GetTargetValue
// 0xfb2ad0 NiPSysInitialRotSpeedVarCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysInitialRotSpeedVarCtlr.h"
#include "gamebryo/niparticle/NiPSysRotationModifierFields.h"

void NiPSysInitialRotSpeedVarCtlr::GetTargetValue(float& value) const
{
    value = modifier->initialRotationSpeedVariance;
}

void NiPSysInitialRotSpeedVarCtlr::SetTargetValue(float value)
{
    modifier->initialRotationSpeedVariance = value;
}
