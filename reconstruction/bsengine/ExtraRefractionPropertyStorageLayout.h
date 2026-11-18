// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRefractionProperty.h; MIT.
// ExtraRefractionProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRefractionPropertyLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraRefractionPropertyLayout.h.
// ExtraRefractionPropertyStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraRefractionPropertyStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraRefractionPropertyStorageLayout();
    float refractionPower;
    std::uint32_t unk14;
};
static_assert(sizeof(ExtraRefractionPropertyStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRefractionPropertyStorageLayout, refractionPower) == 16, "refractionPower offset");
static_assert(offsetof(ExtraRefractionPropertyStorageLayout, unk14) == 20, "unk14 offset");
}
