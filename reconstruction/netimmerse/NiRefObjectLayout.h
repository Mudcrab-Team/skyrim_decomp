// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiRefObject.h; MIT.
// NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObjectLayout: GUESS(medium) STANDIN; represented layout type names
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
