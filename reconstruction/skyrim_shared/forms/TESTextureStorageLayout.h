// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESTexture.h; MIT.
// TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTextureLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/forms/TESTextureLayout.h.
// TESTextureStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/BaseFormComponentStorageLayout.h"
#include "bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class TESTextureStorageLayout : public BaseFormComponentStorageLayout {
public:
    virtual ~TESTextureStorageLayout();
    BSFixedStringStorageLayout textureName;
};
static_assert(sizeof(TESTextureStorageLayout) == 16, "community represented size");
static_assert(offsetof(TESTextureStorageLayout, textureName) == 8, "textureName offset");
}
