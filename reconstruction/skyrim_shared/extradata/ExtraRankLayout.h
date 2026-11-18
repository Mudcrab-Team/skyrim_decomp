// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRank.h; MIT.
// ExtraRank: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRankLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraRankLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraRankLayout();
    std::int32_t rank;
};
static_assert(sizeof(ExtraRankLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRankLayout, rank) == 16, "rank offset");
}
