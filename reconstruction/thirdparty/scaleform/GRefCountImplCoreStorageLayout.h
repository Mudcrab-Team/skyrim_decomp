// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GRefCountImplCore.h; MIT.
// GRefCountImplCore: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GRefCountImplCoreLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GRefCountImplCoreLayout.h.
// GRefCountImplCoreStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class GRefCountImplCoreStorageLayout {
public:
    virtual ~GRefCountImplCoreStorageLayout();
    volatile std::uint32_t _refCount;
};
static_assert(sizeof(GRefCountImplCoreStorageLayout) == 16, "community represented size");
static_assert(offsetof(GRefCountImplCoreStorageLayout, _refCount) == 8, "_refCount offset");
}
