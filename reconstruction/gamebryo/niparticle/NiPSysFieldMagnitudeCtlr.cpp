// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfafec0 NiPSysFieldMagnitudeCtlr::GetTargetValue
// 0xfafed0 NiPSysFieldMagnitudeCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysFieldMagnitudeCtlr.h"
#include "gamebryo/niparticle/NiPSysFieldModifierFields.h"

void NiPSysFieldMagnitudeCtlr::GetTargetValue(float& value) const
{
    value = modifier->magnitude;
}

void NiPSysFieldMagnitudeCtlr::SetTargetValue(float value)
{
    modifier->magnitude = value;
}
