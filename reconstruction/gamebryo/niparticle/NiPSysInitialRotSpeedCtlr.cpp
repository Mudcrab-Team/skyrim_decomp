// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb26c0 NiPSysInitialRotSpeedCtlr::GetTargetValue
// 0xfb26d0 NiPSysInitialRotSpeedCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysInitialRotSpeedCtlr.h"
#include "gamebryo/niparticle/NiPSysRotationModifierFields.h"

void NiPSysInitialRotSpeedCtlr::GetTargetValue(float& value) const
{
    value = modifier->initialRotationSpeed;
}

void NiPSysInitialRotSpeedCtlr::SetTargetValue(float value)
{
    modifier->initialRotationSpeed = value;
}
