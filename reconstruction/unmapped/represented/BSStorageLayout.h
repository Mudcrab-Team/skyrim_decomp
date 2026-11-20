// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSStorage.h; MIT.
// BSStorage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSStorageLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSIntrusiveRefCountedLayout.h"

namespace ResearchLayouts {
class UnkData;
class BSStorageLayout : public BSIntrusiveRefCountedLayout {
public:
    virtual ~BSStorageLayout();
    bool swapBytes;
    bool unk0D;
    uint16_t unk0E;
    UnkData* unk10;
    std::uint64_t unk18;
};
static_assert(sizeof(BSStorageLayout) == 32, "community represented size");
static_assert(offsetof(BSStorageLayout, swapBytes) == 12, "swapBytes offset");
static_assert(offsetof(BSStorageLayout, unk0D) == 13, "unk0D offset");
static_assert(offsetof(BSStorageLayout, unk0E) == 14, "unk0E offset");
static_assert(offsetof(BSStorageLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(BSStorageLayout, unk18) == 24, "unk18 offset");
}
