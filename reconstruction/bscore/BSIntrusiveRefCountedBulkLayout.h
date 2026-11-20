// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSIntrusiveRefCounted.h; MIT.
// BSIntrusiveRefCounted: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSIntrusiveRefCountedLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSIntrusiveRefCountedLayout.h.
// BSIntrusiveRefCountedStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
// Code origin: declarations adapted from the pinned represented community header; no implementation bodies reused.
// BSIntrusiveRefCountedBulkLayout: GUESS(medium) STANDIN; represented layout aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSIntrusiveRefCountedBulkLayout {
public:
    volatile std::uint32_t _refCount;
};
static_assert(sizeof(BSIntrusiveRefCountedBulkLayout) == 4, "community represented size");
static_assert(offsetof(BSIntrusiveRefCountedBulkLayout, _refCount) == 0, "_refCount offset");
}
