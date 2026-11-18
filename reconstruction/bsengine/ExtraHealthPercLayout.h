// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraHealthPerc.h; MIT.
// ExtraHealthPerc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraHealthPercLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraHealthPercLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraHealthPercLayout();
    std::uint32_t unk10;
};
static_assert(sizeof(ExtraHealthPercLayout) == 24, "community represented size");
static_assert(offsetof(ExtraHealthPercLayout, unk10) == 16, "unk10 offset");
}
