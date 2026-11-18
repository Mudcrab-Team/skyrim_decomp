// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkCollisionObject.h; MIT.
// bhkCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BhkCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BhkNiCollisionObjectLayout.h"

namespace ResearchLayouts {
class BhkCollisionObjectLayout : public BhkNiCollisionObjectLayout {
public:
    virtual ~BhkCollisionObjectLayout();
};
static_assert(sizeof(BhkCollisionObjectLayout) == 40, "community represented size");
}
