// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESCondition.h; MIT.
// TESCondition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESConditionLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class TESConditionItem;
class TESConditionLayout {
public:
    TESConditionItem* head;
};
static_assert(sizeof(TESConditionLayout) == 8, "community represented size");
static_assert(offsetof(TESConditionLayout, head) == 0, "head offset");
}
