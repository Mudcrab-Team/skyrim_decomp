// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActiveEffectReferenceEffectController.h; MIT.
// ActiveEffectReferenceEffectController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffectReferenceEffectControllerLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "../../skyrim/papyrus/LayoutValueTypes.h"
#include "ReferenceEffectControllerLayout_5c5a10.h"

namespace ResearchLayouts {
class ActiveEffectLayout;
class ActiveEffectReferenceEffectControllerLayout : public ReferenceEffectControllerLayout {
public:
    virtual ~ActiveEffectReferenceEffectControllerLayout();
    ActiveEffectLayout* effect;
    ObjectRefHandle target;
    NiPoint3 windPoint;
};
static_assert(sizeof(ActiveEffectReferenceEffectControllerLayout) == 32, "community represented size");
static_assert(offsetof(ActiveEffectReferenceEffectControllerLayout, effect) == 8, "effect offset");
static_assert(offsetof(ActiveEffectReferenceEffectControllerLayout, target) == 16, "target offset");
static_assert(offsetof(ActiveEffectReferenceEffectControllerLayout, windPoint) == 20, "windPoint offset");
}
