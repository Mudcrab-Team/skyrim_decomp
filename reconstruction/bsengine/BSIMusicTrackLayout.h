// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIMusicTrack.h; MIT.
// BSIMusicTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSIMusicTrackLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSIMusicTrackLayout {
public:
    virtual ~BSIMusicTrackLayout();
    std::uint32_t trackStatus;
};
static_assert(sizeof(BSIMusicTrackLayout) == 16, "community represented size");
static_assert(offsetof(BSIMusicTrackLayout, trackStatus) == 8, "trackStatus offset");
}
