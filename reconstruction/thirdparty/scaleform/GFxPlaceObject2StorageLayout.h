// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxPlaceObject2.h; MIT.
// GFxPlaceObject2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxPlaceObject2Layout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GFxPlaceObject2Layout.h.
// GFxPlaceObject2StorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "GFxPlaceObjectBaseStorageLayout.h"

namespace ResearchLayouts {
class GFxPlaceObject2StorageLayout : public GFxPlaceObjectBaseStorageLayout {
public:
    virtual ~GFxPlaceObject2StorageLayout();
    char data[1];
};
static_assert(sizeof(GFxPlaceObject2StorageLayout) == 16, "community represented size");
static_assert(offsetof(GFxPlaceObject2StorageLayout, data) == 8, "data offset");
}
