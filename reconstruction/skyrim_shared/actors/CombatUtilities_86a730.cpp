// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x86a730 CombatUtilities::CalculateDistanceSquared
// Adapted bodies: CombatUtilities::CalculateDistanceSquared from the sibling source named in the header
#include "CombatUtilities_86a730.h"

float CombatUtilities::CalculateDistanceSquared(const TESObjectREFR* a_ref1, const TESObjectREFR* a_ref2)
{
    BGSWorldLocation location1 = a_ref1->GetWorldLocation();
    BGSWorldLocation location2 = a_ref2->GetWorldLocation();
    return location1.GetDistanceSquared(location2);
}
