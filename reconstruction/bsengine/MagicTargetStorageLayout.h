// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MagicTarget.h; MIT.
// MagicTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTargetLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/MagicTargetLayout.h.
// MagicTargetStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class SpellDispelData;
class MagicTargetStorageLayout {
public:
    virtual ~MagicTargetStorageLayout();
    SpellDispelData* postUpdateDispelList;
    std::uint8_t flags;
};
static_assert(sizeof(MagicTargetStorageLayout) == 24, "community represented size");
static_assert(offsetof(MagicTargetStorageLayout, postUpdateDispelList) == 8, "postUpdateDispelList offset");
static_assert(offsetof(MagicTargetStorageLayout, flags) == 16, "flags offset");
}
