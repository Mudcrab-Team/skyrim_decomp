// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/SyncQueueObj.h; MIT.
// SyncQueueObj: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SyncQueueObjLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/SyncQueueObjLayout.h.
// SyncQueueObjStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSIntrusiveRefCountedStorageLayout.h"

namespace ResearchLayouts {
class SyncQueueObjStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~SyncQueueObjStorageLayout();
    std::uint32_t unk0C;
};
static_assert(sizeof(SyncQueueObjStorageLayout) == 16, "community represented size");
static_assert(offsetof(SyncQueueObjStorageLayout, unk0C) == 12, "unk0C offset");
}
