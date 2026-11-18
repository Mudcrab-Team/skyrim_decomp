// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraShouldWear.h; MIT.
// ExtraShouldWear: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraShouldWearLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraShouldWearLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraShouldWearLayout();
    std::uint64_t unk10;
};
static_assert(sizeof(ExtraShouldWearLayout) == 24, "community represented size");
static_assert(offsetof(ExtraShouldWearLayout, unk10) == 16, "unk10 offset");
}
