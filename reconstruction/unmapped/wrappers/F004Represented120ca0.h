// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented120ca0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/scaleform/GRefCountImplCoreLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GRefCountImplCore.h; MIT.
// GRefCountImplCore: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented120ca0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class F004Represented120ca0 {
public:
    virtual ~F004Represented120ca0();
    volatile std::uint32_t _refCount;
};
static_assert(sizeof(F004Represented120ca0) == 16, "community represented size");
static_assert(offsetof(F004Represented120ca0, _refCount) == 8, "_refCount offset");
}
