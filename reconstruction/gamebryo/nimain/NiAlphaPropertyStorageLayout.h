// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiAlphaProperty.h; MIT.
// NiAlphaProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAlphaPropertyLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiAlphaPropertyLayout.h.
// NiAlphaPropertyStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "NiPropertyStorageLayout.h"

namespace ResearchLayouts {
class NiAlphaPropertyStorageLayout : public NiPropertyStorageLayout {
public:
    virtual ~NiAlphaPropertyStorageLayout();
    std::uint16_t alphaFlags;
    std::uint8_t alphaThreshold;
};
static_assert(sizeof(NiAlphaPropertyStorageLayout) == 56, "community represented size");
static_assert(offsetof(NiAlphaPropertyStorageLayout, alphaFlags) == 48, "alphaFlags offset");
static_assert(offsetof(NiAlphaPropertyStorageLayout, alphaThreshold) == 50, "alphaThreshold offset");
}
