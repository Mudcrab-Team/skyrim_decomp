// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraHealthPerc.h; MIT.
// ExtraHealthPerc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraHealthPercLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraHealthPercLayout.h.
// ExtraHealthPercStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraHealthPercStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraHealthPercStorageLayout();
    std::uint32_t unk10;
};
static_assert(sizeof(ExtraHealthPercStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraHealthPercStorageLayout, unk10) == 16, "unk10 offset");
}
