// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered5c4620, object: GUESS(low) STANDIN
// CloakEffect: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CloakEffect.h; MIT.
// CloakEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered5c4620: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ActiveEffectLayout.h"

namespace ResearchLayouts {
class F004Recovered5c4620 : public ActiveEffectLayout {
public:
    virtual ~F004Recovered5c4620();
    std::uint64_t nextTargetCheck;
};
static_assert(sizeof(F004Recovered5c4620) == 152, "community represented size");
static_assert(offsetof(F004Recovered5c4620, nextTargetCheck) == 144, "nextTargetCheck offset");
}
