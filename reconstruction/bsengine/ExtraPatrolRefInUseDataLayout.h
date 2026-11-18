// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraPatrolRefInUseData.h; MIT.
// ExtraPatrolRefInUseData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPatrolRefInUseDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraPatrolRefInUseDataLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraPatrolRefInUseDataLayout();
    std::uint32_t user;
};
static_assert(sizeof(ExtraPatrolRefInUseDataLayout) == 24, "community represented size");
static_assert(offsetof(ExtraPatrolRefInUseDataLayout, user) == 16, "user offset");
}
