// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRank.h; MIT.
// ExtraRank: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRankLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraRankLayout.h.
// ExtraRankStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraRankStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraRankStorageLayout();
    std::int32_t rank;
};
static_assert(sizeof(ExtraRankStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRankStorageLayout, rank) == 16, "rank offset");
}
