// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemPotion.h; MIT.
// CombatInventoryItemPotion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemPotionLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/ai/combat/CombatInventoryItemMagicLayout.h"

namespace ResearchLayouts {
class CombatInventoryItemPotionLayout : public CombatInventoryItemMagicLayout {
public:
    virtual ~CombatInventoryItemPotionLayout();
};
static_assert(sizeof(CombatInventoryItemPotionLayout) == 80, "community represented size");
}
