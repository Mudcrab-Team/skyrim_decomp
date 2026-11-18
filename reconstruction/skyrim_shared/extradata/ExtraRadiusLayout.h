// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRadius.h; MIT.
// ExtraRadius: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRadiusLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraRadiusLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraRadiusLayout();
    float radius;
};
static_assert(sizeof(ExtraRadiusLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRadiusLayout, radius) == 16, "radius offset");
}
