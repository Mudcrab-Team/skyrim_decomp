// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxRemoveObject.h; MIT.
// GFxRemoveObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxRemoveObjectLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GFxRemoveObjectLayout.h.
// GFxRemoveObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "GASExecuteTagStorageLayout.h"

namespace ResearchLayouts {
class GFxRemoveObjectStorageLayout : public GASExecuteTagStorageLayout {
public:
    virtual ~GFxRemoveObjectStorageLayout();
    std::uint16_t characterId;
    std::uint16_t depth;
};
static_assert(sizeof(GFxRemoveObjectStorageLayout) == 16, "community represented size");
static_assert(offsetof(GFxRemoveObjectStorageLayout, characterId) == 8, "characterId offset");
static_assert(offsetof(GFxRemoveObjectStorageLayout, depth) == 10, "depth offset");
}
