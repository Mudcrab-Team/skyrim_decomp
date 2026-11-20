// Source exposure: mixed (pinned image and public GetWaterHeight behavior).
// Code origin: original reconstruction from the observed cache and cell fallback.
// Consulted: powerof3/CommonLibSSE@654e55f src/RE/T/TESObjectREFR.cpp (GPL-3.0).
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x2f5860 TESObjectREFR::GetWaterHeight
#include "TESObjectREFR_2f5860.h"

#include <cfloat>

float TESObjectREFR::GetWaterHeight() const
{
    constexpr auto noWater = -FLT_MAX;
    float height;
    if (const auto* data = loadedData) {
        height = data->relevantWaterHeight;
        if (height != noWater) {
            return height;
        }
    } else {
        height = noWater;
    }

    if (const auto* cell = parentCell) {
        return cell->GetExteriorWaterHeight();
    }
    return height;
}
