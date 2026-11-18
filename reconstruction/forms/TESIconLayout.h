// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESIcon.h; MIT.
// TESIcon: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESIconLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "forms/TESTextureLayout.h"

namespace ResearchLayouts {
class TESIconLayout : public TESTextureLayout {
public:
    virtual ~TESIconLayout();
};
static_assert(sizeof(TESIconLayout) == 16, "community represented size");
}
