// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItem.h; MIT.
// CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "CombatObjectLayout.h"
#include "../../../bscore/BSFixedStringLayout.h"

namespace ResearchLayouts {
class TESForm;
class CombatInventoryItemLayout : public CombatObjectLayout {
public:
    virtual ~CombatInventoryItemLayout();
    TESForm* item;
    float itemScore;
    std::uint32_t unk1C;
    CombatInventoryItemSlotLayout itemSlot;
};
static_assert(sizeof(CombatInventoryItemLayout) == 48, "community represented size");
static_assert(offsetof(CombatInventoryItemLayout, item) == 16, "item offset");
static_assert(offsetof(CombatInventoryItemLayout, itemScore) == 24, "itemScore offset");
static_assert(offsetof(CombatInventoryItemLayout, unk1C) == 28, "unk1C offset");
static_assert(offsetof(CombatInventoryItemLayout, itemSlot) == 32, "itemSlot offset");
}
