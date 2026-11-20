// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction of the observed property access.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb02c0 NiPSysFieldMaxDistanceCtlr::GetTargetValue
// 0xfb02d0 NiPSysFieldMaxDistanceCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysFieldMaxDistanceCtlr.h"
#include "gamebryo/niparticle/NiPSysFieldModifierFields.h"

void NiPSysFieldMaxDistanceCtlr::GetTargetValue(float& value) const
{
    value = modifier->maxDistance;
}

void NiPSysFieldMaxDistanceCtlr::SetTargetValue(float value)
{
    auto* field = modifier;
    field->maxDistance = value;
    field->maxDistanceSquared = value * value;
}
