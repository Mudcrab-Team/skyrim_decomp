// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiRefObject.h; MIT.
// NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObjectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class NiRefObjectLayout {
public:
    virtual ~NiRefObjectLayout();
    volatile std::uint32_t _refCount;
};
static_assert(sizeof(NiRefObjectLayout) == 16, "community represented size");
static_assert(offsetof(NiRefObjectLayout, _refCount) == 8, "_refCount offset");
}
