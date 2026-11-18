// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxInitImportActions.h; MIT.
// GFxInitImportActions: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxInitImportActionsLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "thirdparty/scaleform/GASExecuteTagLayout.h"

namespace ResearchLayouts {
class GFxInitImportActionsLayout : public GASExecuteTagLayout {
public:
    virtual ~GFxInitImportActionsLayout();
    std::uint32_t movieIndex;
};
static_assert(sizeof(GFxInitImportActionsLayout) == 16, "community represented size");
static_assert(offsetof(GFxInitImportActionsLayout, movieIndex) == 8, "movieIndex offset");
}
