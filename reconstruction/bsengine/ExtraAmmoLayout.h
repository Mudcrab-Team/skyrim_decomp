// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraAmmo.h; MIT.
// ExtraAmmo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraAmmoLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraAmmoLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraAmmoLayout();
    std::uint64_t unk10;
    std::uint32_t unk18;
};
static_assert(sizeof(ExtraAmmoLayout) == 32, "community represented size");
static_assert(offsetof(ExtraAmmoLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(ExtraAmmoLayout, unk18) == 24, "unk18 offset");
}
