// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below. Stamped as a twin of matched 0x2f94e0 (unmapped/represented/F004Recovered2f94e0): source copied, names replaced by placeholders.
// F004Recovered59dea0, object: GUESS(low) STANDIN
// bhkRigidBody: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkRigidBody.h; MIT.
// bhkRigidBody: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered59dea0: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"
#include "BhkEntityLayout.h"

namespace ResearchLayouts {
class F004Recovered59dea0 : public BhkEntityLayout {
public:
    virtual ~F004Recovered59dea0();
    BSTArray<void*> unk28;
};
static_assert(sizeof(F004Recovered59dea0) == 64, "community represented size");
static_assert(offsetof(F004Recovered59dea0, unk28) == 40, "unk28 offset");
}
