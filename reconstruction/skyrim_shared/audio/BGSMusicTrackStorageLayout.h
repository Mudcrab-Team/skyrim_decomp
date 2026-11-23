// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSMusicTrack.h; MIT.
// BGSMusicTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicTrackLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/forms/BGSMusicTrackLayout.h.
// BGSMusicTrackStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsaudio/BSIMusicTrackStorageLayout.h"
#include "../conditions/TESConditionStorageLayout.h"

namespace ResearchLayouts {
class BGSMusicTrackStorageLayout : public BSIMusicTrackStorageLayout {
public:
    virtual ~BGSMusicTrackStorageLayout();
    TESConditionStorageLayout conditions;
    std::uint64_t unk18;
};
static_assert(sizeof(BGSMusicTrackStorageLayout) == 32, "community represented size");
static_assert(offsetof(BGSMusicTrackStorageLayout, conditions) == 16, "conditions offset");
static_assert(offsetof(BGSMusicTrackStorageLayout, unk18) == 24, "unk18 offset");
}
