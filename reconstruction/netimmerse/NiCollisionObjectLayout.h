// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiCollisionObject.h; MIT.
// NiCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "netimmerse/NiObjectLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class NiCollisionObjectLayout : public NiObjectLayout {
public:
    virtual ~NiCollisionObjectLayout();
    NiAVObject* sceneObject;
};
static_assert(sizeof(NiCollisionObjectLayout) == 24, "community represented size");
static_assert(offsetof(NiCollisionObjectLayout, sceneObject) == 16, "sceneObject offset");
}
