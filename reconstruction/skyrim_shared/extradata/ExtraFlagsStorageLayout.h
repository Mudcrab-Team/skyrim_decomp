// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraFlags.h; MIT.
// ExtraFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraFlagsLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraFlagsLayout.h.
// ExtraFlagsStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraFlagsStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraFlagsStorageLayout();
    std::uint32_t flags;
};
static_assert(sizeof(ExtraFlagsStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraFlagsStorageLayout, flags) == 16, "flags offset");
}
