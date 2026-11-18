// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxPlaceObject2.h; MIT.
// GFxPlaceObject2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxPlaceObject2Layout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "scaleform/GFxPlaceObjectBaseLayout.h"

namespace ResearchLayouts {
class GFxPlaceObject2Layout : public GFxPlaceObjectBaseLayout {
public:
    virtual ~GFxPlaceObject2Layout();
    char data[1];
};
static_assert(sizeof(GFxPlaceObject2Layout) == 16, "community represented size");
static_assert(offsetof(GFxPlaceObject2Layout, data) == 8, "data offset");
}
