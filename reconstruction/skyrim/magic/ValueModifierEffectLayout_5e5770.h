// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/V/ValueModifierEffect.h; MIT.
// ValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ValueModifierEffectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ActiveEffectLayout_5e5770.h"
#include "../papyrus/LayoutValueTypes_5e5770.h"

namespace ResearchLayouts {
class ValueModifierEffectLayout : public ActiveEffectLayout {
public:
    virtual ~ValueModifierEffectLayout();
    ActorValue actorValue;
    float value;
};
static_assert(sizeof(ValueModifierEffectLayout) == 152, "community represented size");
static_assert(offsetof(ValueModifierEffectLayout, actorValue) == 144, "actorValue offset");
static_assert(offsetof(ValueModifierEffectLayout, value) == 148, "value offset");
}
