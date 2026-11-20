// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/bhkShapeCollection.h; MIT.
// bhkShapeCollection: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BhkShapeCollectionLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BhkShapeLayout.h"

namespace ResearchLayouts {
class BhkShapeCollectionLayout : public BhkShapeLayout {
public:
    virtual ~BhkShapeCollectionLayout();
};
static_assert(sizeof(BhkShapeCollectionLayout) == 40, "community represented size");
}
