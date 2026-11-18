// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSMusicTrack.h; MIT.
// BGSMusicTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMusicTrackLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSIMusicTrackLayout.h"
#include "forms/TESConditionLayout.h"

namespace ResearchLayouts {
class BGSMusicTrackLayout : public BSIMusicTrackLayout {
public:
    virtual ~BGSMusicTrackLayout();
    TESConditionLayout conditions;
    std::uint64_t unk18;
};
static_assert(sizeof(BGSMusicTrackLayout) == 32, "community represented size");
static_assert(offsetof(BGSMusicTrackLayout, conditions) == 16, "conditions offset");
static_assert(offsetof(BGSMusicTrackLayout, unk18) == 24, "unk18 offset");
}
