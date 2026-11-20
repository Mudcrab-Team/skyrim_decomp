// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemMagic.h; MIT.
// CombatInventoryItemMagic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemMagicLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/actors/CombatInventoryItemMagicLayout.h.
// CombatInventoryItemMagicStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "CombatInventoryItemStorageLayout.h"

namespace ResearchLayouts {
class Effect;
class CombatInventoryItemMagicStorageLayout : public CombatInventoryItemStorageLayout {
public:
    virtual ~CombatInventoryItemMagicStorageLayout();
    float minRange;
    float maxRange;
    float tacticalDuration;
    float power;
    float currentAV;
    Effect* effect;
};
static_assert(sizeof(CombatInventoryItemMagicStorageLayout) == 80, "community represented size");
static_assert(offsetof(CombatInventoryItemMagicStorageLayout, minRange) == 48, "minRange offset");
static_assert(offsetof(CombatInventoryItemMagicStorageLayout, maxRange) == 52, "maxRange offset");
static_assert(offsetof(CombatInventoryItemMagicStorageLayout, tacticalDuration) == 56, "tacticalDuration offset");
static_assert(offsetof(CombatInventoryItemMagicStorageLayout, power) == 60, "power offset");
static_assert(offsetof(CombatInventoryItemMagicStorageLayout, currentAV) == 64, "currentAV offset");
static_assert(offsetof(CombatInventoryItemMagicStorageLayout, effect) == 72, "effect offset");
}
