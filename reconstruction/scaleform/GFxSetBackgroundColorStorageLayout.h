// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GFxSetBackgroundColor.h; MIT.
// GFxSetBackgroundColor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxSetBackgroundColorLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GFxSetBackgroundColorLayout.h.
// GFxSetBackgroundColorStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "GASExecuteTagStorageLayout.h"

namespace ResearchLayouts {
class GFxSetBackgroundColorStorageLayout : public GASExecuteTagStorageLayout {
public:
    virtual ~GFxSetBackgroundColorStorageLayout();
    std::uint64_t unk08;
};
static_assert(sizeof(GFxSetBackgroundColorStorageLayout) == 16, "community represented size");
static_assert(offsetof(GFxSetBackgroundColorStorageLayout, unk08) == 8, "unk08 offset");
}
