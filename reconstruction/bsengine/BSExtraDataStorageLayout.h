// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSExtraData.h; MIT.
// BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSExtraDataLayout.h.
// BSExtraDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSExtraDataStorageLayout {
public:
    virtual ~BSExtraDataStorageLayout();
    BSExtraDataStorageLayout* next;
};
static_assert(sizeof(BSExtraDataStorageLayout) == 16, "community represented size");
static_assert(offsetof(BSExtraDataStorageLayout, next) == 8, "next offset");
}
