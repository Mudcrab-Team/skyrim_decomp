// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below. Stamped as a twin of matched 0x5ba8b0 (unmapped/represented/F004Recovered5ba8b0): source copied, names replaced by placeholders.
// F004Recovered138680, object: GUESS(low) STANDIN
// AccumulatingValueModifierEffect: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/AccumulatingValueModifierEffect.h; MIT.
// AccumulatingValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered138680: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ValueModifierEffectLayout.h"

namespace ResearchLayouts {
class F004Recovered138680 : public ValueModifierEffectLayout {
public:
    virtual ~F004Recovered138680();
    float accumulatedMagnitude;
    float maximumMagnitude;
    float holdTimer;
};
static_assert(sizeof(F004Recovered138680) == 168, "community represented size");
static_assert(offsetof(F004Recovered138680, accumulatedMagnitude) == 152, "accumulatedMagnitude offset");
static_assert(offsetof(F004Recovered138680, maximumMagnitude) == 156, "maximumMagnitude offset");
static_assert(offsetof(F004Recovered138680, holdTimer) == 160, "holdTimer offset");
}
