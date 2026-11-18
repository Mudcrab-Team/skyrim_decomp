// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxPlaceObject2a.h; MIT.
// GFxPlaceObject2a: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxPlaceObject2aLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GFxPlaceObject2aLayout.h.
// GFxPlaceObject2aStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "GFxPlaceObject2StorageLayout.h"

namespace ResearchLayouts {
class GFxPlaceObject2aStorageLayout : public GFxPlaceObject2StorageLayout {
public:
    virtual ~GFxPlaceObject2aStorageLayout();
};
static_assert(sizeof(GFxPlaceObject2aStorageLayout) == 16, "community represented size");
}
