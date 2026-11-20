// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfa4870 NiPSysAirFieldInheritVelocityCtlr::GetTargetValue
// Adapted bodies: none
#include "NiPSysAirFieldInheritVelocityCtlr.h"
#include "gamebryo/niparticle/NiPSysAirFieldModifierFields.h"

void NiPSysAirFieldInheritVelocityCtlr::GetTargetValue(float& value) const
{
    value = modifier->inheritVelocity;
}
