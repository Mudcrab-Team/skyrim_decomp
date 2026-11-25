// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf69300 FloatSyncLeaff69300::SynchronizePoseInterpolator
#include "FloatSyncLeaff69300_f69300.h"

static bool IsFloatType(const FloatTypef69300* current)
{
    while (current) {
        if (current == &gFloatTypef69300) {
            return true;
        }
        current = current->parent;
    }
    return false;
}

static FloatInterpolatorf69300* CastToFloat(FloatInterpolatorf69300* interpolator)
{
    if (!interpolator) {
        return nullptr;
    }
    return IsFloatType(interpolator->GetType()) ? interpolator : nullptr;
}

void FloatSyncLeaff69300::SynchronizePoseInterpolator(FloatInterpolatorf69300* interpolator, std::uint16_t)
{
    auto* value = CastToFloat(interpolator);
    value->SetValue(data->value);
}
