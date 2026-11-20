// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GRefCountImplCore.h; MIT.
// GRefCountImplCore: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GRefCountImplCoreLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class GRefCountImplCoreLayout {
public:
    virtual ~GRefCountImplCoreLayout();
    volatile std::uint32_t _refCount;
};
static_assert(sizeof(GRefCountImplCoreLayout) == 16, "community represented size");
static_assert(offsetof(GRefCountImplCoreLayout, _refCount) == 8, "_refCount offset");
}
