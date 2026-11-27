// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: TestBit, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// 0x6c63f0 Actor::CheckClampDamageModifier_1406222F0
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "Actor_6c63f0.h"

// Clamp a negative actor-value damage delta against non-negative bounds and essential health floor.
float Actor::CheckClampDamageModifier_1406222F0(std::int32_t a_av, float a_delta)
{
    float result = a_delta;
    if (a_delta < 0.0f) {
        ActorValueInfo* info = g_actorValueList6c63f0->actorValues[a_av];
        if (TestBit(info->flags, 5)) {
            float current = avOwner.GetBaseActorValue(static_cast<std::uint32_t>(a_av)) +
                            GetActorValueModifier(1, static_cast<std::uint32_t>(a_av)) +
                            GetActorValueModifier(2, static_cast<std::uint32_t>(a_av));
            if (current < -result) {
                result = -current;
            }
        }
    }
    if (IsEssential(true) && a_av == 0x18 && a_delta < 0.0f) {
        float health = avOwner.GetActorValue(static_cast<std::uint32_t>(a_av));
        float floorVal = g_essentialHealthFloor6c63f0;
        if (health + a_delta < floorVal) {
            if (health > floorVal) {
                return -(health - floorVal);
            }
            return g_zeroClamp6c63f0;
        }
    }
    return result;
}
