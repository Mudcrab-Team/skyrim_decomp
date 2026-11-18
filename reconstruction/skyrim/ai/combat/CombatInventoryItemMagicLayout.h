// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemMagic.h; MIT.
// CombatInventoryItemMagic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemMagicLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "CombatInventoryItemLayout.h"

namespace ResearchLayouts {
class Effect;
class CombatInventoryItemMagicLayout : public CombatInventoryItemLayout {
public:
    virtual ~CombatInventoryItemMagicLayout();
    float minRange;
    float maxRange;
    float tacticalDuration;
    float power;
    float currentAV;
    Effect* effect;
};
static_assert(sizeof(CombatInventoryItemMagicLayout) == 80, "community represented size");
static_assert(offsetof(CombatInventoryItemMagicLayout, minRange) == 48, "minRange offset");
static_assert(offsetof(CombatInventoryItemMagicLayout, maxRange) == 52, "maxRange offset");
static_assert(offsetof(CombatInventoryItemMagicLayout, tacticalDuration) == 56, "tacticalDuration offset");
static_assert(offsetof(CombatInventoryItemMagicLayout, power) == 60, "power offset");
static_assert(offsetof(CombatInventoryItemMagicLayout, currentAV) == 64, "currentAV offset");
static_assert(offsetof(CombatInventoryItemMagicLayout, effect) == 72, "effect offset");
}
