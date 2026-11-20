// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MultiBoundMarkerData.h; MIT.
// MultiBoundMarkerData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MultiBoundMarkerDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/MultiBoundMarkerDataLayout.h.
// MultiBoundMarkerDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"
#include "../../bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class MultiBoundMarkerDataStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~MultiBoundMarkerDataStorageLayout();
    NiPoint3StorageLayout halfExtents;
};
static_assert(sizeof(MultiBoundMarkerDataStorageLayout) == 32, "community represented size");
static_assert(offsetof(MultiBoundMarkerDataStorageLayout, halfExtents) == 16, "halfExtents offset");
}
