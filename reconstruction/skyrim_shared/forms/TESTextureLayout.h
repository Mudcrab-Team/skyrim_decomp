// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESTexture.h; MIT.
// TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTextureLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/BaseFormComponentLayout.h"
#include "bscore/BSFixedStringLayout.h"

namespace ResearchLayouts {
class TESTextureLayout : public BaseFormComponentLayout {
public:
    virtual ~TESTextureLayout();
    BSFixedStringLayout textureName;
};
static_assert(sizeof(TESTextureLayout) == 16, "community represented size");
static_assert(offsetof(TESTextureLayout, textureName) == 8, "textureName offset");
}
