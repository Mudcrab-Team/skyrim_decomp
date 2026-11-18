// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraAmmo.h; MIT.
// ExtraAmmo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraAmmoLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraAmmoLayout.h.
// ExtraAmmoStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraAmmoStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraAmmoStorageLayout();
    std::uint64_t unk10;
    std::uint32_t unk18;
};
static_assert(sizeof(ExtraAmmoStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraAmmoStorageLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(ExtraAmmoStorageLayout, unk18) == 24, "unk18 offset");
}
