// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCellSkyRegion.h; MIT.
// ExtraCellSkyRegion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCellSkyRegionLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraCellSkyRegionLayout.h.
// ExtraCellSkyRegionStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class TESRegion;
class ExtraCellSkyRegionStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraCellSkyRegionStorageLayout();
    TESRegion* skyRegion;
};
static_assert(sizeof(ExtraCellSkyRegionStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraCellSkyRegionStorageLayout, skyRegion) == 16, "skyRegion offset");
}
