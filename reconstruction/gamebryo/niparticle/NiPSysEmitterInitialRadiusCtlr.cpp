// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfae6c0 NiPSysEmitterInitialRadiusCtlr::GetTargetValue
// 0xfae6d0 NiPSysEmitterInitialRadiusCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysEmitterInitialRadiusCtlr.h"
#include "gamebryo/niparticle/NiPSysEmitterFields.h"

void NiPSysEmitterInitialRadiusCtlr::GetTargetValue(float& value) const
{
    value = modifier->initialRadius;
}

void NiPSysEmitterInitialRadiusCtlr::SetTargetValue(float value)
{
    modifier->initialRadius = value;
}
