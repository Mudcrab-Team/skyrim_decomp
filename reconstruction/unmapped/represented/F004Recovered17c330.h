// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered17c330, object: GUESS(low) STANDIN
// ExtraAttachedArrows3D: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraAttachedArrows3D.h; MIT.
// ExtraAttachedArrows3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered17c330: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataLayout.h"
#include "LayoutValueTypes.h"

namespace ResearchLayouts {
class DataItem;
class F004Recovered17c330 : public BSExtraDataLayout {
public:
    virtual ~F004Recovered17c330();
    BSTArray<DataItem> data;
    std::uint16_t nextStorage;
    std::uint16_t oldestStorage;
};
static_assert(sizeof(F004Recovered17c330) == 48, "community represented size");
static_assert(offsetof(F004Recovered17c330, data) == 16, "data offset");
static_assert(offsetof(F004Recovered17c330, nextStorage) == 40, "nextStorage offset");
static_assert(offsetof(F004Recovered17c330, oldestStorage) == 42, "oldestStorage offset");
}
