// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered458eb0, object: GUESS(low) STANDIN
// BGSProcedureTreeBranch: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSProcedureTreeBranch.h; MIT.
// BGSProcedureTreeBranch: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered458eb0: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"
#include "BGSProcedureTreeConditionalItemLayout.h"

namespace ResearchLayouts {
class BGSProcedureTreeConditionalItemLayout;
class F004Recovered458eb0 : public BGSProcedureTreeConditionalItemLayout {
public:
    virtual ~F004Recovered458eb0();
    BSTArray<BGSProcedureTreeConditionalItemLayout*> conditions;
    std::uint64_t unk28;
};
static_assert(sizeof(F004Recovered458eb0) == 48, "community represented size");
static_assert(offsetof(F004Recovered458eb0, conditions) == 16, "conditions offset");
static_assert(offsetof(F004Recovered458eb0, unk28) == 40, "unk28 offset");
}
