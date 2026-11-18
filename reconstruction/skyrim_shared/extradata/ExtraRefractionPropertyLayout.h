// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRefractionProperty.h; MIT.
// ExtraRefractionProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRefractionPropertyLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraRefractionPropertyLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraRefractionPropertyLayout();
    float refractionPower;
    std::uint32_t unk14;
};
static_assert(sizeof(ExtraRefractionPropertyLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRefractionPropertyLayout, refractionPower) == 16, "refractionPower offset");
static_assert(offsetof(ExtraRefractionPropertyLayout, unk14) == 20, "unk14 offset");
}
