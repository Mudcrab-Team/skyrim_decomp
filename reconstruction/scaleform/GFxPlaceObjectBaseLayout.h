// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxPlaceObjectBase.h; MIT.
// GFxPlaceObjectBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxPlaceObjectBaseLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "scaleform/GASExecuteTagLayout.h"

namespace ResearchLayouts {
class GFxPlaceObjectBaseLayout : public GASExecuteTagLayout {
public:
    virtual ~GFxPlaceObjectBaseLayout();
};
static_assert(sizeof(GFxPlaceObjectBaseLayout) == 8, "community represented size");
}
