// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiPSysModifier.h; MIT.
// NiPSysModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifierLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiPSysModifierLayout.h.
// NiPSysModifierStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringStorageLayout.h"
#include "NiObjectStorageLayout.h"

namespace ResearchLayouts {
class NiParticleSystem;
class NiPSysModifierStorageLayout : public NiObjectStorageLayout {
public:
    virtual ~NiPSysModifierStorageLayout();
    BSFixedStringStorageLayout name;
    std::uint32_t order;
    NiParticleSystem* target;
    bool active;
};
static_assert(sizeof(NiPSysModifierStorageLayout) == 48, "community represented size");
static_assert(offsetof(NiPSysModifierStorageLayout, name) == 16, "name offset");
static_assert(offsetof(NiPSysModifierStorageLayout, order) == 24, "order offset");
static_assert(offsetof(NiPSysModifierStorageLayout, target) == 32, "target offset");
static_assert(offsetof(NiPSysModifierStorageLayout, active) == 40, "active offset");
}
