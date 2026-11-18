// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatObject.h; MIT.
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../../../gamebryo/nimain/NiRefObjectLayout.h"

namespace ResearchLayouts {
class CombatObjectLayout : public NiRefObjectLayout {
public:
    virtual ~CombatObjectLayout();
};
static_assert(sizeof(CombatObjectLayout) == 16, "community represented size");
}
