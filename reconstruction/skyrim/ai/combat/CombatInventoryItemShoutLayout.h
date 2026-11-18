// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemShout.h; MIT.
// CombatInventoryItemShout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemShoutLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/ai/combat/CombatInventoryItemMagicLayout.h"

namespace ResearchLayouts {
class CombatInventoryItemShoutLayout : public CombatInventoryItemMagicLayout {
public:
    virtual ~CombatInventoryItemShoutLayout();
};
static_assert(sizeof(CombatInventoryItemShoutLayout) == 80, "community represented size");
}
