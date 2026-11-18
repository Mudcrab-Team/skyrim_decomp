// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemScroll.h; MIT.
// CombatInventoryItemScroll: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemScrollLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "actors/CombatInventoryItemMagicLayout.h"

namespace ResearchLayouts {
class CombatInventoryItemScrollLayout : public CombatInventoryItemMagicLayout {
public:
    virtual ~CombatInventoryItemScrollLayout();
};
static_assert(sizeof(CombatInventoryItemScrollLayout) == 80, "community represented size");
}
