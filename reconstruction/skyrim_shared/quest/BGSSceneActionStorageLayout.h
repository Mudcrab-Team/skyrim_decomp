// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSSceneAction.h; MIT.
// BGSSceneAction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSceneActionLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/forms/BGSSceneActionLayout.h.
// BGSSceneActionStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BGSSceneActionStorageLayout {
public:
    virtual ~BGSSceneActionStorageLayout();
    std::uint32_t actorID;
    std::uint16_t startPhase;
    std::uint16_t endPhase;
    std::uint32_t flags;
    std::uint8_t unk14;
    std::uint8_t unk15;
    std::uint16_t unk16;
    std::uint32_t index;
    std::uint32_t unk1C;
};
static_assert(sizeof(BGSSceneActionStorageLayout) == 32, "community represented size");
static_assert(offsetof(BGSSceneActionStorageLayout, actorID) == 8, "actorID offset");
static_assert(offsetof(BGSSceneActionStorageLayout, startPhase) == 12, "startPhase offset");
static_assert(offsetof(BGSSceneActionStorageLayout, endPhase) == 14, "endPhase offset");
static_assert(offsetof(BGSSceneActionStorageLayout, flags) == 16, "flags offset");
static_assert(offsetof(BGSSceneActionStorageLayout, unk14) == 20, "unk14 offset");
static_assert(offsetof(BGSSceneActionStorageLayout, unk15) == 21, "unk15 offset");
static_assert(offsetof(BGSSceneActionStorageLayout, unk16) == 22, "unk16 offset");
static_assert(offsetof(BGSSceneActionStorageLayout, index) == 24, "index offset");
static_assert(offsetof(BGSSceneActionStorageLayout, unk1C) == 28, "unk1C offset");
}
