// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxPlaceObject.h; MIT.
// GFxPlaceObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxPlaceObjectLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GFxPlaceObjectLayout.h.
// GFxPlaceObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "GFxPlaceObjectBaseStorageLayout.h"

namespace ResearchLayouts {
class GFxPlaceObjectStorageLayout : public GFxPlaceObjectBaseStorageLayout {
public:
    virtual ~GFxPlaceObjectStorageLayout();
    char data[1];
};
static_assert(sizeof(GFxPlaceObjectStorageLayout) == 16, "community represented size");
static_assert(offsetof(GFxPlaceObjectStorageLayout, data) == 8, "data offset");
}
