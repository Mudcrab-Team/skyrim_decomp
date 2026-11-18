// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/R/ReferenceEffectController.h; MIT.
// ReferenceEffectController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffectControllerLayout: GUESS(medium) STANDIN; represented layout type names
// Code origin: represented declaration from reconstruction/bsengine/ReferenceEffectControllerLayout.h; only include spelling changed.
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
