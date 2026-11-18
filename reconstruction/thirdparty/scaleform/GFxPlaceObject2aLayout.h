// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxPlaceObject2a.h; MIT.
// GFxPlaceObject2a: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxPlaceObject2aLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "thirdparty/scaleform/GFxPlaceObject2Layout.h"

namespace ResearchLayouts {
class GFxPlaceObject2aLayout : public GFxPlaceObject2Layout {
public:
    virtual ~GFxPlaceObject2aLayout();
};
static_assert(sizeof(GFxPlaceObject2aLayout) == 16, "community represented size");
}
