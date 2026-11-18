// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxSetBackgroundColor.h; MIT.
// GFxSetBackgroundColor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxSetBackgroundColorLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "scaleform/GASExecuteTagLayout.h"

namespace ResearchLayouts {
class GFxSetBackgroundColorLayout : public GASExecuteTagLayout {
public:
    virtual ~GFxSetBackgroundColorLayout();
    std::uint64_t unk08;
};
static_assert(sizeof(GFxSetBackgroundColorLayout) == 16, "community represented size");
static_assert(offsetof(GFxSetBackgroundColorLayout, unk08) == 8, "unk08 offset");
}
