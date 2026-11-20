// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered1f3a60, object: GUESS(low) STANDIN
// ActionInput: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActionInput.h; MIT.
// ActionInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ExtraStorageValueTypesLayout.h"

namespace ResearchLayouts {
class BGSAction;
class TESObjectREFR;
class F004Recovered1f3a60 {
public:
    virtual ~F004Recovered1f3a60();
    NiPointer<TESObjectREFR> source;
    NiPointer<TESObjectREFR> target;
    BGSAction* action;
    uint32_t unk20;
};
static_assert(sizeof(F004Recovered1f3a60) == 40, "community represented size");
static_assert(offsetof(F004Recovered1f3a60, source) == 8, "source offset");
static_assert(offsetof(F004Recovered1f3a60, target) == 16, "target offset");
static_assert(offsetof(F004Recovered1f3a60, action) == 24, "action offset");
static_assert(offsetof(F004Recovered1f3a60, unk20) == 32, "unk20 offset");
}
