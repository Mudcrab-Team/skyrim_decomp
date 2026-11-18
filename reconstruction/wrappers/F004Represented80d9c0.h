// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented80d9c0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/actors/CombatObjectLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatObject.h; MIT.
// CombatObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented80d9c0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/NiRefObjectLayout.h"

namespace ResearchLayouts {
class F004Represented80d9c0 : public NiRefObjectLayout {
public:
    virtual ~F004Represented80d9c0();
};
static_assert(sizeof(F004Represented80d9c0) == 16, "community represented size");
}
