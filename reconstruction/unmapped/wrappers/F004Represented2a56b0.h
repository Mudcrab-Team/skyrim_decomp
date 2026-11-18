// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented2a56b0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/ImageSpaceModifierInstanceTempLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/ImageSpaceModifierInstanceTemp.h; MIT.
// ImageSpaceModifierInstanceTemp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented2a56b0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../support/ImageSpaceModifierInstanceLayout.h"

namespace ResearchLayouts {
class F004Represented2a56b0 : public ImageSpaceModifierInstanceLayout {
public:
    virtual ~F004Represented2a56b0();
    float duration;
};
static_assert(sizeof(F004Represented2a56b0) == 48, "community represented size");
static_assert(offsetof(F004Represented2a56b0, duration) == 40, "duration offset");
}
