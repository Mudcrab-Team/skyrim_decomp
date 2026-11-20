// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered328770, object: GUESS(low) STANDIN
// BSIMusicType: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIMusicType.h; MIT.
// BSIMusicType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered328770: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"

namespace ResearchLayouts {
class BSIMusicTrack;
class F004Recovered328770 {
public:
    virtual ~F004Recovered328770();
    std::uint32_t flags;
    std::uint8_t priority;
    std::uint16_t ducksOtherMusicBy;
    float fadeTime;
    std::uint32_t currentTrackIndex;
    BSTArray<std::uint32_t> trackHistory;
    BSTArray<BSIMusicTrack*> tracks;
    std::uint32_t typeStatus;
};
static_assert(sizeof(F004Recovered328770) == 80, "community represented size");
static_assert(offsetof(F004Recovered328770, flags) == 8, "flags offset");
static_assert(offsetof(F004Recovered328770, priority) == 12, "priority offset");
static_assert(offsetof(F004Recovered328770, ducksOtherMusicBy) == 14, "ducksOtherMusicBy offset");
static_assert(offsetof(F004Recovered328770, fadeTime) == 16, "fadeTime offset");
static_assert(offsetof(F004Recovered328770, currentTrackIndex) == 20, "currentTrackIndex offset");
static_assert(offsetof(F004Recovered328770, trackHistory) == 24, "trackHistory offset");
static_assert(offsetof(F004Recovered328770, tracks) == 48, "tracks offset");
static_assert(offsetof(F004Recovered328770, typeStatus) == 72, "typeStatus offset");
}
