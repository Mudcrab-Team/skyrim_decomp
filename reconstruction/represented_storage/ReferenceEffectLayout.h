// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/R/ReferenceEffect.h; MIT.
// ReferenceEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReferenceEffectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSTempEffectLayout.h"
#include "LayoutValueTypes.h"

namespace ResearchLayouts {
class ReferenceEffectControllerLayout;
class ReferenceEffectLayout : public BSTempEffectLayout {
public:
    virtual ~ReferenceEffectLayout();
    ReferenceEffectControllerLayout* controller;
    ObjectRefHandle target;
    ObjectRefHandle aimAtTarget;
    bool finished;
    bool ownController;
};
static_assert(sizeof(ReferenceEffectLayout) == 72, "community represented size");
static_assert(offsetof(ReferenceEffectLayout, controller) == 48, "controller offset");
static_assert(offsetof(ReferenceEffectLayout, target) == 56, "target offset");
static_assert(offsetof(ReferenceEffectLayout, aimAtTarget) == 60, "aimAtTarget offset");
static_assert(offsetof(ReferenceEffectLayout, finished) == 64, "finished offset");
static_assert(offsetof(ReferenceEffectLayout, ownController) == 65, "ownController offset");
}
