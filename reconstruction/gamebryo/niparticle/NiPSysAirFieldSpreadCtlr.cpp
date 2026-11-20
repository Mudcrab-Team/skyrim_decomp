// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfa6290 NiPSysAirFieldSpreadCtlr::GetTargetValue
// Adapted bodies: none
#include "NiPSysAirFieldSpreadCtlr.h"
#include "gamebryo/niparticle/NiPSysAirFieldModifierFields.h"

void NiPSysAirFieldSpreadCtlr::GetTargetValue(float& value) const
{
    value = modifier->spread;
}
