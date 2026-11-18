// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkPCollisionObject.h; MIT.
// bhkPCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BhkPCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BhkPCollisionObjectLayout.h.
// BhkPCollisionObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BhkNiCollisionObjectStorageLayout.h"

namespace ResearchLayouts {
class BhkPCollisionObjectStorageLayout : public BhkNiCollisionObjectStorageLayout {
public:
    virtual ~BhkPCollisionObjectStorageLayout();
};
static_assert(sizeof(BhkPCollisionObjectStorageLayout) == 40, "community represented size");
}
