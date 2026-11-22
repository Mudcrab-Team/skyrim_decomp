// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented82fa90, object: GUESS(low) STANDIN
// Declaration source: reconstruction/actors/CombatInventoryItemMagicLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemMagic.h; MIT.
// CombatInventoryItemMagic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented82fa90: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "unmapped/support/CombatInventoryItemLayout.h"

namespace ResearchLayouts {
class Effect;
class F004Represented82fa90 : public CombatInventoryItemLayout {
public:
    virtual ~F004Represented82fa90();
    float minRange;
    float maxRange;
    float tacticalDuration;
    float power;
    float currentAV;
    Effect* effect;
};
static_assert(sizeof(F004Represented82fa90) == 80, "community represented size");
static_assert(offsetof(F004Represented82fa90, minRange) == 48, "minRange offset");
static_assert(offsetof(F004Represented82fa90, maxRange) == 52, "maxRange offset");
static_assert(offsetof(F004Represented82fa90, tacticalDuration) == 56, "tacticalDuration offset");
static_assert(offsetof(F004Represented82fa90, power) == 60, "power offset");
static_assert(offsetof(F004Represented82fa90, currentAV) == 64, "currentAV offset");
static_assert(offsetof(F004Represented82fa90, effect) == 72, "effect offset");
}
