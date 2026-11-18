// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/H/hkpRayHitCollector.h; MIT.
// hkpRayHitCollector: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HkpRayHitCollectorLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class HkpRayHitCollectorLayout {
public:
    virtual ~HkpRayHitCollectorLayout();
    float earlyOutHitFraction;
};
static_assert(sizeof(HkpRayHitCollectorLayout) == 16, "community represented size");
static_assert(offsetof(HkpRayHitCollectorLayout, earlyOutHitFraction) == 8, "earlyOutHitFraction offset");
}
