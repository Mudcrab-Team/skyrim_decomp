// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiPSysModifier.h; MIT.
// NiPSysModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifierLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringLayout.h"
#include "netimmerse/NiObjectLayout.h"

namespace ResearchLayouts {
class NiParticleSystem;
class NiPSysModifierLayout : public NiObjectLayout {
public:
    virtual ~NiPSysModifierLayout();
    BSFixedStringLayout name;
    std::uint32_t order;
    NiParticleSystem* target;
    bool active;
};
static_assert(sizeof(NiPSysModifierLayout) == 48, "community represented size");
static_assert(offsetof(NiPSysModifierLayout, name) == 16, "name offset");
static_assert(offsetof(NiPSysModifierLayout, order) == 24, "order offset");
static_assert(offsetof(NiPSysModifierLayout, target) == 32, "target offset");
static_assert(offsetof(NiPSysModifierLayout, active) == 40, "active offset");
}
