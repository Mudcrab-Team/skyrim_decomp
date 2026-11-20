// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfafac0 NiPSysFieldAttenuationCtlr::GetTargetValue
// 0xfafad0 NiPSysFieldAttenuationCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysFieldAttenuationCtlr.h"
#include "gamebryo/niparticle/NiPSysFieldModifierFields.h"

void NiPSysFieldAttenuationCtlr::GetTargetValue(float& value) const
{
    value = modifier->attenuation;
}

void NiPSysFieldAttenuationCtlr::SetTargetValue(float value)
{
    modifier->attenuation = value;
}
