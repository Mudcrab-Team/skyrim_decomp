// Source exposure: mixed (pinned image and public GetSubmergeLevel behavior).
// Code origin: original reconstruction from the observed water-height fallback and depth clamp.
// Consulted: powerof3/CommonLibSSE@654e55f src/RE/T/TESObjectREFR.cpp (GPL-3.0).
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x685c30 TESObjectREFR::GetSubmergeLevel
#include "TESObjectREFR_685c30.h"

#include <cfloat>

float TESObjectREFR::GetSubmergeLevel(float height, TESObjectCELL* cell) const
{
    float surface;
    if (cell && cell != parentCell) {
        surface = cell->GetExteriorWaterHeight();
    } else {
        surface = GetWaterHeight();
    }

    if (surface == -FLT_MAX && cell) {
        surface = cell->GetExteriorWaterHeight();
    }

    if (surface > height) {
        const auto depth = surface - height;
        const auto fraction = depth / GetHeight();
        return fraction < 1.0f ? fraction : 1.0f;
    }
    return 0.0f;
}
