// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSShaderMaterial.h; MIT.
// BSShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderMaterialLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSIntrusiveRefCountedLayout.h"
#include "bscore/BSFixedStringLayout.h"

namespace ResearchLayouts {
class BSShaderMaterialLayout : public BSIntrusiveRefCountedLayout {
public:
    virtual ~BSShaderMaterialLayout();
    NiPoint2Layout texCoordOffset[2];
    NiPoint2Layout texCoordScale[2];
    std::uint32_t hashKey;
    std::uint32_t unk30;
    std::uint32_t unk34;
};
static_assert(sizeof(BSShaderMaterialLayout) == 56, "community represented size");
static_assert(offsetof(BSShaderMaterialLayout, texCoordOffset) == 12, "texCoordOffset offset");
static_assert(offsetof(BSShaderMaterialLayout, texCoordScale) == 28, "texCoordScale offset");
static_assert(offsetof(BSShaderMaterialLayout, hashKey) == 44, "hashKey offset");
static_assert(offsetof(BSShaderMaterialLayout, unk30) == 48, "unk30 offset");
static_assert(offsetof(BSShaderMaterialLayout, unk34) == 52, "unk34 offset");
}
