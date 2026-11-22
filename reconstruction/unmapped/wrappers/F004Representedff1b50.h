// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Representedff1b50, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/BSBoundLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSBound.h; MIT.
// BSBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Representedff1b50: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "unmapped/support/BSFixedStringLayout.h"
#include "unmapped/support/NiExtraDataLayout.h"

namespace ResearchLayouts {
class F004Representedff1b50 : public NiExtraDataLayout {
public:
    virtual ~F004Representedff1b50();
    NiPoint3Layout center;
    NiPoint3Layout extents;
};
static_assert(sizeof(F004Representedff1b50) == 48, "community represented size");
static_assert(offsetof(F004Representedff1b50, center) == 24, "center offset");
static_assert(offsetof(F004Representedff1b50, extents) == 36, "extents offset");
}
