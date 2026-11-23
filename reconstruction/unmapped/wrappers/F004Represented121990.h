// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented121990, object: GUESS(low) STANDIN
// Declaration source: reconstruction/scaleform/GRefCountImplLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GRefCountImpl.h; MIT.
// GRefCountImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented121990: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../support/GRefCountImplCoreLayout.h"

namespace ResearchLayouts {
class F004Represented121990 : public GRefCountImplCoreLayout {
public:
    virtual ~F004Represented121990();
};
static_assert(sizeof(F004Represented121990) == 16, "community represented size");
}
