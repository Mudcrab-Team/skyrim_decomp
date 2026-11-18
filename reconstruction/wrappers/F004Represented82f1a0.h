// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented82f1a0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/actors/CombatInventoryItemLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItem.h; MIT.
// CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented82f1a0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/CombatObjectLayout.h"
#include "../f004support/BSFixedStringLayout.h"

namespace ResearchLayouts {
class TESForm;
class F004Represented82f1a0 : public CombatObjectLayout {
public:
    virtual ~F004Represented82f1a0();
    TESForm* item;
    float itemScore;
    std::uint32_t unk1C;
    CombatInventoryItemSlotLayout itemSlot;
};
static_assert(sizeof(F004Represented82f1a0) == 48, "community represented size");
static_assert(offsetof(F004Represented82f1a0, item) == 16, "item offset");
static_assert(offsetof(F004Represented82f1a0, itemScore) == 24, "itemScore offset");
static_assert(offsetof(F004Represented82f1a0, unk1C) == 28, "unk1C offset");
static_assert(offsetof(F004Represented82f1a0, itemSlot) == 32, "itemSlot offset");
}
