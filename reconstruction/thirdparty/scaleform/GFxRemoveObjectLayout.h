// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxRemoveObject.h; MIT.
// GFxRemoveObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxRemoveObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "thirdparty/scaleform/GASExecuteTagLayout.h"

namespace ResearchLayouts {
class GFxRemoveObjectLayout : public GASExecuteTagLayout {
public:
    virtual ~GFxRemoveObjectLayout();
    std::uint16_t characterId;
    std::uint16_t depth;
};
static_assert(sizeof(GFxRemoveObjectLayout) == 16, "community represented size");
static_assert(offsetof(GFxRemoveObjectLayout, characterId) == 8, "characterId offset");
static_assert(offsetof(GFxRemoveObjectLayout, depth) == 10, "depth offset");
}
