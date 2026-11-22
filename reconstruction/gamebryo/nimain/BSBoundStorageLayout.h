// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSBound.h; MIT.
// BSBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBoundLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSBoundLayout.h.
// BSBoundStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSFixedStringStorageLayout.h"
#include "gamebryo/nimain/NiExtraDataStorageLayout.h"

namespace ResearchLayouts {
class BSBoundStorageLayout : public NiExtraDataStorageLayout {
public:
    virtual ~BSBoundStorageLayout();
    NiPoint3StorageLayout center;
    NiPoint3StorageLayout extents;
};
static_assert(sizeof(BSBoundStorageLayout) == 48, "community represented size");
static_assert(offsetof(BSBoundStorageLayout, center) == 24, "center offset");
static_assert(offsetof(BSBoundStorageLayout, extents) == 36, "extents offset");
}
