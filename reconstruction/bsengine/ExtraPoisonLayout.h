// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraPoison.h; MIT.
// ExtraPoison: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPoisonLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class AlchemyItem;
class ExtraPoisonLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraPoisonLayout();
    AlchemyItem* poison;
    std::uint32_t count;
};
static_assert(sizeof(ExtraPoisonLayout) == 32, "community represented size");
static_assert(offsetof(ExtraPoisonLayout, poison) == 16, "poison offset");
static_assert(offsetof(ExtraPoisonLayout, count) == 24, "count offset");
}
