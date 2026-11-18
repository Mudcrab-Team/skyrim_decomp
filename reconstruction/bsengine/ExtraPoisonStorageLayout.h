// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraPoison.h; MIT.
// ExtraPoison: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPoisonLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraPoisonLayout.h.
// ExtraPoisonStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class AlchemyItem;
class ExtraPoisonStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraPoisonStorageLayout();
    AlchemyItem* poison;
    std::uint32_t count;
};
static_assert(sizeof(ExtraPoisonStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraPoisonStorageLayout, poison) == 16, "poison offset");
static_assert(offsetof(ExtraPoisonStorageLayout, count) == 24, "count offset");
}
