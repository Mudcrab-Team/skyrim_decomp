// Source exposure: mixed (pinned-image observations; community-generated names).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0xfc0bd0 NiPSysModifierFloatCtlr::SynchronizePoseInterpolator
// Adapted bodies: none
#include "NiPSysModifierFloatCtlr_fc0bd0.h"

namespace {
bool IsFloatType(const NiRTTI* type)
{
    while (type) {
        if (type == &NiFloatInterpolator_RTTI)
            return true;
        type = type->parent;
    }
    return false;
}

NiFloatInterpolator* AsFloatInterpolator(NiInterpolator* interpolator)
{
    if (!interpolator)
        return nullptr;
    const NiRTTI* type = interpolator->vtable->GetRTTI(interpolator);
    return IsFloatType(type) ? static_cast<NiFloatInterpolator*>(interpolator) : nullptr;
}
}

void NiPSysModifierFloatCtlr::SynchronizePoseInterpolator(NiInterpolator* interpolator, std::uint16_t)
{
    auto floatInterpolator = AsFloatInterpolator(interpolator);
    float value;
    vtable->GetTargetFloatValue(this, value);
    floatInterpolator->SetPoseValue(value);
}
