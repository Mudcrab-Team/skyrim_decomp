// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf7c280 ColorSyncLeaff7c280::SynchronizePoseInterpolator
#include "ColorSyncLeaff7c280_f7c280.h"

static bool IsColorType(const ColorTypef7c280* current)
{
    while (current) {
        if (current == &gColorTypef7c280) {
            return true;
        }
        current = current->parent;
    }
    return false;
}

static ColorInterpolatorf7c280* CastToColor(ColorInterpolatorf7c280* interpolator)
{
    if (!interpolator) {
        return nullptr;
    }
    return IsColorType(interpolator->GetType()) ? interpolator : nullptr;
}

void ColorSyncLeaff7c280::SynchronizePoseInterpolator(ColorInterpolatorf7c280* interpolator, std::uint16_t)
{
    auto* value = CastToColor(interpolator);
    value->SetValue(data->value);
}
