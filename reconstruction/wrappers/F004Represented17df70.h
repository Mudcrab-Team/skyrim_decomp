// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented17df70, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/MagicTargetLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MagicTarget.h; MIT.
// MagicTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented17df70: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class SpellDispelData;
class F004Represented17df70 {
public:
    virtual ~F004Represented17df70();
    SpellDispelData* postUpdateDispelList;
    std::uint8_t flags;
};
static_assert(sizeof(F004Represented17df70) == 24, "community represented size");
static_assert(offsetof(F004Represented17df70, postUpdateDispelList) == 8, "postUpdateDispelList offset");
static_assert(offsetof(F004Represented17df70, flags) == 16, "flags offset");
}
