// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxRemoveObject2.h; MIT.
// GFxRemoveObject2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxRemoveObject2Layout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "scaleform/GASExecuteTagLayout.h"

namespace ResearchLayouts {
class GFxRemoveObject2Layout : public GASExecuteTagLayout {
public:
    virtual ~GFxRemoveObject2Layout();
    std::uint16_t depth;
};
static_assert(sizeof(GFxRemoveObject2Layout) == 16, "community represented size");
static_assert(offsetof(GFxRemoveObject2Layout, depth) == 8, "depth offset");
}
