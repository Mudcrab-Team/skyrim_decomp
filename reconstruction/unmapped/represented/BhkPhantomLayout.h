// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkPhantom.h; MIT.
// bhkPhantom: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BhkPhantomLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BhkWorldObjectLayout.h"

namespace ResearchLayouts {
class BhkPhantomLayout : public BhkWorldObjectLayout {
public:
    virtual ~BhkPhantomLayout();
    std::uint64_t unk28;
};
static_assert(sizeof(BhkPhantomLayout) == 48, "community represented size");
static_assert(offsetof(BhkPhantomLayout, unk28) == 40, "unk28 offset");
}
