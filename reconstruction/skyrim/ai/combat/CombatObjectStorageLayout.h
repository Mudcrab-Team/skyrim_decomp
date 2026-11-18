// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatObject.h; MIT.
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatObjectLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/actors/CombatObjectLayout.h.
// CombatObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "gamebryo/nimain/NiRefObjectStorageLayout.h"

namespace ResearchLayouts {
class CombatObjectStorageLayout : public NiRefObjectStorageLayout {
public:
    virtual ~CombatObjectStorageLayout();
};
static_assert(sizeof(CombatObjectStorageLayout) == 16, "community represented size");
}
