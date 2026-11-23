// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented17d180, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/ExtraMagicLightLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraMagicLight.h; MIT.
// ExtraMagicLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented17d180: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../support/ExtraLightLayout.h"

namespace ResearchLayouts {
class F004Represented17d180 : public ExtraLightLayout {
public:
    virtual ~F004Represented17d180();
};
static_assert(sizeof(F004Represented17d180) == 24, "community represented size");
}
