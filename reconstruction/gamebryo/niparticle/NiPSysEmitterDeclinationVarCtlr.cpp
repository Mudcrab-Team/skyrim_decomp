// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfae2c0 NiPSysEmitterDeclinationVarCtlr::GetTargetValue
// 0xfae2d0 NiPSysEmitterDeclinationVarCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterDeclinationVarCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterDeclinationVarCtlr::GetTargetValue(float& value) const
{
    value = modifier->declinationVariance;
}

void NiPSysEmitterDeclinationVarCtlr::SetTargetValue(float value)
{
    modifier->declinationVariance = value;
}
