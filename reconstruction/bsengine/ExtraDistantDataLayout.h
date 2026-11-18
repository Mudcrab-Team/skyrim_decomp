// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraDistantData.h; MIT.
// ExtraDistantData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDistantDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"
#include "bsengine/BSFixedStringLayout.h"

namespace ResearchLayouts {
class ExtraDistantDataLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraDistantDataLayout();
    NiPoint3Layout landNormal;
};
static_assert(sizeof(ExtraDistantDataLayout) == 32, "community represented size");
static_assert(offsetof(ExtraDistantDataLayout, landNormal) == 16, "landNormal offset");
}
