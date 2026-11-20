// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfaeac0 NiPSysEmitterLifeSpanCtlr::GetTargetValue
// 0xfaead0 NiPSysEmitterLifeSpanCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterLifeSpanCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterLifeSpanCtlr::GetTargetValue(float& value) const
{
    value = modifier->lifeSpan;
}

void NiPSysEmitterLifeSpanCtlr::SetTargetValue(float value)
{
    modifier->lifeSpan = value;
}
