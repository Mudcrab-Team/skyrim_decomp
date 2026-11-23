// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRefrPath.h; MIT.
// ExtraRefrPath: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRefrPathLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraRefrPathLayout.h.
// ExtraRefrPathStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"
#include "../../bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class ExtraRefrPathStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraRefrPathStorageLayout();
    NiPoint3StorageLayout startPos;
    NiPoint3StorageLayout startTangent;
    NiPoint3StorageLayout startEuler;
    NiPoint3StorageLayout goalPos;
    NiPoint3StorageLayout goalTangent;
    NiPoint3StorageLayout goalEuler;
    float speed;
    float maxRotSpeed;
    float currentParameter;
    std::uint32_t type;
};
static_assert(sizeof(ExtraRefrPathStorageLayout) == 104, "community represented size");
static_assert(offsetof(ExtraRefrPathStorageLayout, startPos) == 16, "startPos offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, startTangent) == 28, "startTangent offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, startEuler) == 40, "startEuler offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, goalPos) == 52, "goalPos offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, goalTangent) == 64, "goalTangent offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, goalEuler) == 76, "goalEuler offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, speed) == 88, "speed offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, maxRotSpeed) == 92, "maxRotSpeed offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, currentParameter) == 96, "currentParameter offset");
static_assert(offsetof(ExtraRefrPathStorageLayout, type) == 100, "type offset");
}
