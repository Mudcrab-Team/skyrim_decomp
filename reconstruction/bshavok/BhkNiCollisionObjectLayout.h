// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkNiCollisionObject.h; MIT.
// bhkNiCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BhkNiCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSFixedStringLayout.h"
#include "gamebryo/nimain/NiCollisionObjectLayout.h"

namespace ResearchLayouts {
class bhkWorldObject;
class BhkNiCollisionObjectLayout : public NiCollisionObjectLayout {
public:
    virtual ~BhkNiCollisionObjectLayout();
    std::uint32_t flags;
    NiPointerLayout<bhkWorldObject> body;
};
static_assert(sizeof(BhkNiCollisionObjectLayout) == 40, "community represented size");
static_assert(offsetof(BhkNiCollisionObjectLayout, flags) == 24, "flags offset");
static_assert(offsetof(BhkNiCollisionObjectLayout, body) == 32, "body offset");
}
