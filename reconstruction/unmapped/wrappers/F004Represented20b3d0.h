// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented20b3d0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/netimmerse/NiAlphaPropertyLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiAlphaProperty.h; MIT.
// NiAlphaProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented20b3d0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "unmapped/support/NiPropertyLayout.h"

namespace ResearchLayouts {
class F004Represented20b3d0 : public NiPropertyLayout {
public:
    virtual ~F004Represented20b3d0();
    std::uint16_t alphaFlags;
    std::uint8_t alphaThreshold;
};
static_assert(sizeof(F004Represented20b3d0) == 56, "community represented size");
static_assert(offsetof(F004Represented20b3d0, alphaFlags) == 48, "alphaFlags offset");
static_assert(offsetof(F004Represented20b3d0, alphaThreshold) == 50, "alphaThreshold offset");
}
