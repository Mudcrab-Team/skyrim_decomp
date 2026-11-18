// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCellImageSpace.h; MIT.
// ExtraCellImageSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCellImageSpaceLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESImageSpace;
class ExtraCellImageSpaceLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraCellImageSpaceLayout();
    TESImageSpace* imageSpace;
};
static_assert(sizeof(ExtraCellImageSpaceLayout) == 24, "community represented size");
static_assert(offsetof(ExtraCellImageSpaceLayout, imageSpace) == 16, "imageSpace offset");
}
