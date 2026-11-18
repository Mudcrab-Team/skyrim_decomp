// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraLevCreaModifier.h; MIT.
// ExtraLevCreaModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraLevCreaModifierLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraLevCreaModifierLayout.h.
// ExtraLevCreaModifierStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraLevCreaModifierStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraLevCreaModifierStorageLayout();
    std::uint32_t modifier;
};
static_assert(sizeof(ExtraLevCreaModifierStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraLevCreaModifierStorageLayout, modifier) == 16, "modifier offset");
}
