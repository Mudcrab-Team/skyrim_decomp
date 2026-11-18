// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRefrPath.h; MIT.
// ExtraRefrPath: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRefrPathLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"
#include "bsengine/BSFixedStringLayout.h"

namespace ResearchLayouts {
class ExtraRefrPathLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraRefrPathLayout();
    NiPoint3Layout startPos;
    NiPoint3Layout startTangent;
    NiPoint3Layout startEuler;
    NiPoint3Layout goalPos;
    NiPoint3Layout goalTangent;
    NiPoint3Layout goalEuler;
    float speed;
    float maxRotSpeed;
    float currentParameter;
    std::uint32_t type;
};
static_assert(sizeof(ExtraRefrPathLayout) == 104, "community represented size");
static_assert(offsetof(ExtraRefrPathLayout, startPos) == 16, "startPos offset");
static_assert(offsetof(ExtraRefrPathLayout, startTangent) == 28, "startTangent offset");
static_assert(offsetof(ExtraRefrPathLayout, startEuler) == 40, "startEuler offset");
static_assert(offsetof(ExtraRefrPathLayout, goalPos) == 52, "goalPos offset");
static_assert(offsetof(ExtraRefrPathLayout, goalTangent) == 64, "goalTangent offset");
static_assert(offsetof(ExtraRefrPathLayout, goalEuler) == 76, "goalEuler offset");
static_assert(offsetof(ExtraRefrPathLayout, speed) == 88, "speed offset");
static_assert(offsetof(ExtraRefrPathLayout, maxRotSpeed) == 92, "maxRotSpeed offset");
static_assert(offsetof(ExtraRefrPathLayout, currentParameter) == 96, "currentParameter offset");
static_assert(offsetof(ExtraRefrPathLayout, type) == 100, "type offset");
}
