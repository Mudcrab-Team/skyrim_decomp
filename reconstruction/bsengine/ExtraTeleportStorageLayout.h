// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraTeleport.h; MIT.
// ExtraTeleport: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraTeleportLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraTeleportLayout.h.
// ExtraTeleportStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class DoorTeleportData;
class ExtraTeleportStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraTeleportStorageLayout();
    DoorTeleportData* teleportData;
};
static_assert(sizeof(ExtraTeleportStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraTeleportStorageLayout, teleportData) == 16, "teleportData offset");
}
