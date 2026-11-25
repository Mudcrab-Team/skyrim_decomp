// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf7c9f0 FloatsSyncLeaff7c9f0::SynchronizePoseInterpolator
#include "FloatsSyncLeaff7c9f0_f7c9f0.h"

static bool IsFloatType(const FloatsTypef7c9f0* current)
{
    while (current) {
        if (current == &gFloatsTypef7c9f0) {
            return true;
        }
        current = current->parent;
    }
    return false;
}

static FloatsInterpolatorf7c9f0* CastToFloat(FloatsInterpolatorf7c9f0* interpolator)
{
    if (!interpolator) {
        return nullptr;
    }
    return IsFloatType(interpolator->GetType()) ? interpolator : nullptr;
}

void FloatsSyncLeaff7c9f0::SynchronizePoseInterpolator(FloatsInterpolatorf7c9f0* interpolator, std::uint16_t)
{
    auto* value = CastToFloat(interpolator);
    value->SetValue(data->GetValue(index));
}
