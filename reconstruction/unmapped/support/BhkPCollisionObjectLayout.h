// Origin: copied represented declaration from reconstruction/bsengine/BhkPCollisionObjectLayout.h; only include spellings changed.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkPCollisionObject.h; MIT.
// bhkPCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BhkPCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "BhkNiCollisionObjectLayout.h"

namespace ResearchLayouts {
class BhkPCollisionObjectLayout : public BhkNiCollisionObjectLayout {
public:
    virtual ~BhkPCollisionObjectLayout();
};
static_assert(sizeof(BhkPCollisionObjectLayout) == 40, "community represented size");
}
