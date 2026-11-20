// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/D/DemoralizeEffect.h; MIT.
// DemoralizeEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DemoralizeEffectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "TargetValueModifierEffectLayout.h"

namespace ResearchLayouts {
class DemoralizeEffectLayout : public TargetValueModifierEffectLayout {
public:
    virtual ~DemoralizeEffectLayout();
};
static_assert(sizeof(DemoralizeEffectLayout) == 152, "community represented size");
}
