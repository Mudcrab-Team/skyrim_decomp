// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb1ec0 NiPSysInitialRotAngleCtlr::GetTargetValue
// 0xfb1ed0 NiPSysInitialRotAngleCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysInitialRotAngleCtlr.h"
#include "gamebryo/niparticle/NiPSysRotationModifierFields.h"

void NiPSysInitialRotAngleCtlr::GetTargetValue(float& value) const
{
    value = modifier->initialRotationAngle;
}

void NiPSysInitialRotAngleCtlr::SetTargetValue(float value)
{
    modifier->initialRotationAngle = value;
}
