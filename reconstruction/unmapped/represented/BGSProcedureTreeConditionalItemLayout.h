// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSProcedureTreeConditionalItem.h; MIT.
// BGSProcedureTreeConditionalItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSProcedureTreeConditionalItemLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "IProcedureTreeItemLayout.h"
#include "TESConditionLayout.h"

namespace ResearchLayouts {
class BGSProcedureTreeConditionalItemLayout : public IProcedureTreeItemLayout {
public:
    virtual ~BGSProcedureTreeConditionalItemLayout();
    TESConditionLayout conditions;
};
static_assert(sizeof(BGSProcedureTreeConditionalItemLayout) == 16, "community represented size");
static_assert(offsetof(BGSProcedureTreeConditionalItemLayout, conditions) == 8, "conditions offset");
}
