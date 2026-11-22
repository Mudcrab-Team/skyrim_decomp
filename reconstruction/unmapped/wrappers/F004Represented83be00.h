// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented83be00, object: GUESS(low) STANDIN
// Declaration source: reconstruction/actors/CombatInventoryItemScrollLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemScroll.h; MIT.
// CombatInventoryItemScroll: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented83be00: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "unmapped/support/CombatInventoryItemMagicLayout.h"

namespace ResearchLayouts {
class F004Represented83be00 : public CombatInventoryItemMagicLayout {
public:
    virtual ~F004Represented83be00();
};
static_assert(sizeof(F004Represented83be00) == 80, "community represented size");
}
