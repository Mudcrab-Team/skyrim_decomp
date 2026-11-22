// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkNiCollisionObject.h; MIT.
// bhkNiCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BhkNiCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BhkNiCollisionObjectLayout.h.
// BhkNiCollisionObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSFixedStringStorageLayout.h"
#include "gamebryo/nimain/NiCollisionObjectStorageLayout.h"

namespace ResearchLayouts {
class bhkWorldObject;
class BhkNiCollisionObjectStorageLayout : public NiCollisionObjectStorageLayout {
public:
    virtual ~BhkNiCollisionObjectStorageLayout();
    std::uint32_t flags;
    NiPointerStorageLayout<bhkWorldObject> body;
};
static_assert(sizeof(BhkNiCollisionObjectStorageLayout) == 40, "community represented size");
static_assert(offsetof(BhkNiCollisionObjectStorageLayout, flags) == 24, "flags offset");
static_assert(offsetof(BhkNiCollisionObjectStorageLayout, body) == 32, "body offset");
}
