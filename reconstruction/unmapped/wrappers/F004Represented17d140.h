// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented17d140, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/ExtraLockLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraLock.h; MIT.
// ExtraLock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented17d140: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../support/BSExtraDataLayout.h"

namespace ResearchLayouts {
class REFR_LOCK;
class F004Represented17d140 : public BSExtraDataLayout {
public:
    virtual ~F004Represented17d140();
    REFR_LOCK* lock;
};
static_assert(sizeof(F004Represented17d140) == 24, "community represented size");
static_assert(offsetof(F004Represented17d140, lock) == 16, "lock offset");
}
