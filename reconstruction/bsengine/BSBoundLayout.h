// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSBound.h; MIT.
// BSBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBoundLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringLayout.h"
#include "netimmerse/NiExtraDataLayout.h"

namespace ResearchLayouts {
class BSBoundLayout : public NiExtraDataLayout {
public:
    virtual ~BSBoundLayout();
    NiPoint3Layout center;
    NiPoint3Layout extents;
};
static_assert(sizeof(BSBoundLayout) == 48, "community represented size");
static_assert(offsetof(BSBoundLayout, center) == 24, "center offset");
static_assert(offsetof(BSBoundLayout, extents) == 36, "extents offset");
}
