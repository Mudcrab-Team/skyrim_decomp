// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered5c2a80, object: GUESS(low) STANDIN
// MagicItemDataCollector: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MagicItemDataCollector.h; MIT.
// MagicItemDataCollector: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered5c2a80: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"
#include "MagicItemTraversalFunctorLayout.h"

namespace ResearchLayouts {
class Effect;
class F004Recovered5c2a80 : public MagicItemTraversalFunctorLayout {
public:
    virtual ~F004Recovered5c2a80();
    BSTArray<Effect*> projectileEffectList;
    Effect* costliestEffect;
    std::int32_t maxCost;
    Effect* largestAreaEffect;
    float highestArea;
    std::uint32_t flags;
    bool summonsExtraLargeCreature;
};
static_assert(sizeof(F004Recovered5c2a80) == 80, "community represented size");
static_assert(offsetof(F004Recovered5c2a80, projectileEffectList) == 16, "projectileEffectList offset");
static_assert(offsetof(F004Recovered5c2a80, costliestEffect) == 40, "costliestEffect offset");
static_assert(offsetof(F004Recovered5c2a80, maxCost) == 48, "maxCost offset");
static_assert(offsetof(F004Recovered5c2a80, largestAreaEffect) == 56, "largestAreaEffect offset");
static_assert(offsetof(F004Recovered5c2a80, highestArea) == 64, "highestArea offset");
static_assert(offsetof(F004Recovered5c2a80, flags) == 68, "flags offset");
static_assert(offsetof(F004Recovered5c2a80, summonsExtraLargeCreature) == 72, "summonsExtraLargeCreature offset");
}
