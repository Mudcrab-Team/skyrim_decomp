// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCellMusicType.h; MIT.
// ExtraCellMusicType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCellMusicTypeLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraCellMusicTypeLayout.h.
// ExtraCellMusicTypeStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class BGSMusicType;
class ExtraCellMusicTypeStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraCellMusicTypeStorageLayout();
    BGSMusicType* type;
};
static_assert(sizeof(ExtraCellMusicTypeStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraCellMusicTypeStorageLayout, type) == 16, "type offset");
}
