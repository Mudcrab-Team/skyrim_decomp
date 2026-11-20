// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below. Stamped as a twin of matched 0x17c100 (unmapped/represented/F004Recovered17c100): source copied, names replaced by placeholders.
// F004Recovered31f5e0, object: GUESS(low) STANDIN
// ExtraActivateRef: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraActivateRef.h; MIT.
// ExtraActivateRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered31f5e0: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataLayout.h"
#include "LayoutValueTypes.h"

namespace ResearchLayouts {
class REF_ACTIVATE_DATA;
class F004Recovered31f5e0 : public BSExtraDataLayout {
public:
    virtual ~F004Recovered31f5e0();
    BSSimpleList<REF_ACTIVATE_DATA*> parents;
    std::uint8_t activateFlags;
};
static_assert(sizeof(F004Recovered31f5e0) == 40, "community represented size");
static_assert(offsetof(F004Recovered31f5e0, parents) == 16, "parents offset");
static_assert(offsetof(F004Recovered31f5e0, activateFlags) == 32, "activateFlags offset");
}
