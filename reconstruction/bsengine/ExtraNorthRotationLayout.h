// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraNorthRotation.h; MIT.
// ExtraNorthRotation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraNorthRotationLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraNorthRotationLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraNorthRotationLayout();
    float northRot;
};
static_assert(sizeof(ExtraNorthRotationLayout) == 24, "community represented size");
static_assert(offsetof(ExtraNorthRotationLayout, northRot) == 16, "northRot offset");
}
