// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered2f9400, object: GUESS(low) STANDIN
// bhkPhantom: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkPhantom.h; MIT.
// bhkPhantom: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered2f9400: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BhkWorldObjectLayout.h"

namespace ResearchLayouts {
class F004Recovered2f9400 : public BhkWorldObjectLayout {
public:
    virtual ~F004Recovered2f9400();
    std::uint64_t unk28;
};
static_assert(sizeof(F004Recovered2f9400) == 48, "community represented size");
static_assert(offsetof(F004Recovered2f9400, unk28) == 40, "unk28 offset");
}
