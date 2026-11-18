// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSMusicSilenceTrack.h; MIT.
// BGSMusicSilenceTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicSilenceTrackLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/audio/BGSMusicTrackLayout.h"

namespace ResearchLayouts {
class BGSMusicSilenceTrackLayout : public BGSMusicTrackLayout {
public:
    virtual ~BGSMusicSilenceTrackLayout();
    float duration;
    std::uint64_t playTime;
    std::uint64_t pauseTime;
};
static_assert(sizeof(BGSMusicSilenceTrackLayout) == 56, "community represented size");
static_assert(offsetof(BGSMusicSilenceTrackLayout, duration) == 32, "duration offset");
static_assert(offsetof(BGSMusicSilenceTrackLayout, playTime) == 40, "playTime offset");
static_assert(offsetof(BGSMusicSilenceTrackLayout, pauseTime) == 48, "pauseTime offset");
}
