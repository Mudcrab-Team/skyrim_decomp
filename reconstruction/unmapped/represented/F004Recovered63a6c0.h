// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered63a6c0, object: GUESS(low) STANDIN
// LoadStorageWrapper: EXE_RTTI
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/L/LoadStorageWrapper.h; MIT.
// LoadStorageWrapper: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSMemStorageLayout.h"

namespace ResearchLayouts {
class F004Recovered63a6c0 : public BSMemStorageLayout {
public:
    virtual ~F004Recovered63a6c0();
};
static_assert(sizeof(F004Recovered63a6c0) == 48, "community represented size");
}
