// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRoomRefData.h; MIT.
// ExtraRoomRefData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRoomRefDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraRoomRefDataLayout.h.
// ExtraRoomRefDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class RoomRefData;
class ExtraRoomRefDataStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraRoomRefDataStorageLayout();
    RoomRefData* data;
};
static_assert(sizeof(ExtraRoomRefDataStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRoomRefDataStorageLayout, data) == 16, "data offset");
}
