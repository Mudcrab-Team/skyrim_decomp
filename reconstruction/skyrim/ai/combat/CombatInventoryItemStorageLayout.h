// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItem.h; MIT.
// CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/actors/CombatInventoryItemLayout.h.
// CombatInventoryItemStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "CombatObjectStorageLayout.h"
#include "bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class TESForm;
class CombatInventoryItemStorageLayout : public CombatObjectStorageLayout {
public:
    virtual ~CombatInventoryItemStorageLayout();
    TESForm* item;
    float itemScore;
    std::uint32_t unk1C;
    CombatInventoryItemSlotStorageLayout itemSlot;
};
static_assert(sizeof(CombatInventoryItemStorageLayout) == 48, "community represented size");
static_assert(offsetof(CombatInventoryItemStorageLayout, item) == 16, "item offset");
static_assert(offsetof(CombatInventoryItemStorageLayout, itemScore) == 24, "itemScore offset");
static_assert(offsetof(CombatInventoryItemStorageLayout, unk1C) == 28, "unk1C offset");
static_assert(offsetof(CombatInventoryItemStorageLayout, itemSlot) == 32, "itemSlot offset");
}
