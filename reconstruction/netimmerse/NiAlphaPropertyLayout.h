// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiAlphaProperty.h; MIT.
// NiAlphaProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAlphaPropertyLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "netimmerse/NiPropertyLayout.h"

namespace ResearchLayouts {
class NiAlphaPropertyLayout : public NiPropertyLayout {
public:
    virtual ~NiAlphaPropertyLayout();
    std::uint16_t alphaFlags;
    std::uint8_t alphaThreshold;
};
static_assert(sizeof(NiAlphaPropertyLayout) == 56, "community represented size");
static_assert(offsetof(NiAlphaPropertyLayout, alphaFlags) == 48, "alphaFlags offset");
static_assert(offsetof(NiAlphaPropertyLayout, alphaThreshold) == 50, "alphaThreshold offset");
}
