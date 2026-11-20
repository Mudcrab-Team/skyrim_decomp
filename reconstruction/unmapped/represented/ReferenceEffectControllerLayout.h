// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/R/ReferenceEffectController.h; MIT.
// ReferenceEffectController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReferenceEffectControllerLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class ReferenceEffectControllerLayout {
public:
    virtual ~ReferenceEffectControllerLayout();
};
static_assert(sizeof(ReferenceEffectControllerLayout) == 8, "community represented size");
}
