// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSShaderMaterial.h; MIT.
// BSShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderMaterialLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSShaderMaterialLayout.h.
// BSShaderMaterialStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../bscore/BSIntrusiveRefCountedStorageLayout.h"
#include "../bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class BSShaderMaterialStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~BSShaderMaterialStorageLayout();
    NiPoint2StorageLayout texCoordOffset[2];
    NiPoint2StorageLayout texCoordScale[2];
    std::uint32_t hashKey;
    std::uint32_t unk30;
    std::uint32_t unk34;
};
static_assert(sizeof(BSShaderMaterialStorageLayout) == 56, "community represented size");
static_assert(offsetof(BSShaderMaterialStorageLayout, texCoordOffset) == 12, "texCoordOffset offset");
static_assert(offsetof(BSShaderMaterialStorageLayout, texCoordScale) == 28, "texCoordScale offset");
static_assert(offsetof(BSShaderMaterialStorageLayout, hashKey) == 44, "hashKey offset");
static_assert(offsetof(BSShaderMaterialStorageLayout, unk30) == 48, "unk30 offset");
static_assert(offsetof(BSShaderMaterialStorageLayout, unk34) == 52, "unk34 offset");
}
