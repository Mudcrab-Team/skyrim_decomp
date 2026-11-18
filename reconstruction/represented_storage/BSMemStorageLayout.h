// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSMemStorage.h; MIT.
// BSMemStorage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSMemStorageLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSStorageLayout.h"

namespace ResearchLayouts {
class Win32FileType;
class BSMemStorageLayout : public BSStorageLayout {
public:
    virtual ~BSMemStorageLayout();
    Win32FileType* file;
    std::uint64_t unk28;
};
static_assert(sizeof(BSMemStorageLayout) == 48, "community represented size");
static_assert(offsetof(BSMemStorageLayout, file) == 32, "file offset");
static_assert(offsetof(BSMemStorageLayout, unk28) == 40, "unk28 offset");
}
