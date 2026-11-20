// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiCollisionObject.h; MIT.
// NiCollisionObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCollisionObjectLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiCollisionObjectLayout.h.
// NiCollisionObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "NiObjectStorageLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class NiCollisionObjectStorageLayout : public NiObjectStorageLayout {
public:
    virtual ~NiCollisionObjectStorageLayout();
    NiAVObject* sceneObject;
};
static_assert(sizeof(NiCollisionObjectStorageLayout) == 24, "community represented size");
static_assert(offsetof(NiCollisionObjectStorageLayout, sceneObject) == 16, "sceneObject offset");
}
