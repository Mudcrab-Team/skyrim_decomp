// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiPSysGravityModifier.h; MIT.
// NiPSysGravityModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGravityModifierLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringLayout.h"
#include "netimmerse/NiPSysModifierLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class NiPSysGravityModifierLayout : public NiPSysModifierLayout {
public:
    virtual ~NiPSysGravityModifierLayout();
    NiAVObject* gravityObj;
    NiPoint3Layout gravityAxis;
    float decay;
    float strength;
    std::uint32_t forceType;
    float turbulence;
    float scale;
    bool worldAligned;
};
static_assert(sizeof(NiPSysGravityModifierLayout) == 96, "community represented size");
static_assert(offsetof(NiPSysGravityModifierLayout, gravityObj) == 48, "gravityObj offset");
static_assert(offsetof(NiPSysGravityModifierLayout, gravityAxis) == 56, "gravityAxis offset");
static_assert(offsetof(NiPSysGravityModifierLayout, decay) == 68, "decay offset");
static_assert(offsetof(NiPSysGravityModifierLayout, strength) == 72, "strength offset");
static_assert(offsetof(NiPSysGravityModifierLayout, forceType) == 76, "forceType offset");
static_assert(offsetof(NiPSysGravityModifierLayout, turbulence) == 80, "turbulence offset");
static_assert(offsetof(NiPSysGravityModifierLayout, scale) == 84, "scale offset");
static_assert(offsetof(NiPSysGravityModifierLayout, worldAligned) == 88, "worldAligned offset");
}
