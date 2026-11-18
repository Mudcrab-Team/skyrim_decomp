// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkWorldObject.h; MIT.
// bhkWorldObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BhkWorldObjectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BhkSerializableLayout.h"

namespace ResearchLayouts {
class hkpWorld;
class BhkWorldObjectLayout : public BhkSerializableLayout {
public:
    virtual ~BhkWorldObjectLayout();
    hkpWorld* world;
};
static_assert(sizeof(BhkWorldObjectLayout) == 40, "community represented size");
static_assert(offsetof(BhkWorldObjectLayout, world) == 32, "world offset");
}
