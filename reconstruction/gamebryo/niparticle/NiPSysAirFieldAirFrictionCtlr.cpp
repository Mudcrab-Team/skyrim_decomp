// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfa4460 NiPSysAirFieldAirFrictionCtlr::GetTargetValue
// Adapted bodies: none
#include "NiPSysAirFieldAirFrictionCtlr.h"
#include "gamebryo/niparticle/NiPSysAirFieldModifierFields.h"

void NiPSysAirFieldAirFrictionCtlr::GetTargetValue(float& value) const
{
    value = modifier->airFriction;
}
