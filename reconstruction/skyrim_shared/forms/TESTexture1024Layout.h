// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESTexture1024.h; MIT.
// TESTexture1024: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTexture1024Layout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESTextureLayout.h"

namespace ResearchLayouts {
class TESTexture1024Layout : public TESTextureLayout {
public:
    virtual ~TESTexture1024Layout();
};
static_assert(sizeof(TESTexture1024Layout) == 16, "community represented size");
}
