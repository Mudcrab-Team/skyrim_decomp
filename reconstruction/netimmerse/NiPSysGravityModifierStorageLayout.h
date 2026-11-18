// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiPSysGravityModifier.h; MIT.
// NiPSysGravityModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGravityModifierLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiPSysGravityModifierLayout.h.
// NiPSysGravityModifierStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringStorageLayout.h"
#include "NiPSysModifierStorageLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class NiPSysGravityModifierStorageLayout : public NiPSysModifierStorageLayout {
public:
    virtual ~NiPSysGravityModifierStorageLayout();
    NiAVObject* gravityObj;
    NiPoint3StorageLayout gravityAxis;
    float decay;
    float strength;
    std::uint32_t forceType;
    float turbulence;
    float scale;
    bool worldAligned;
};
static_assert(sizeof(NiPSysGravityModifierStorageLayout) == 96, "community represented size");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, gravityObj) == 48, "gravityObj offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, gravityAxis) == 56, "gravityAxis offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, decay) == 68, "decay offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, strength) == 72, "strength offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, forceType) == 76, "forceType offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, turbulence) == 80, "turbulence offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, scale) == 84, "scale offset");
static_assert(offsetof(NiPSysGravityModifierStorageLayout, worldAligned) == 88, "worldAligned offset");
}
