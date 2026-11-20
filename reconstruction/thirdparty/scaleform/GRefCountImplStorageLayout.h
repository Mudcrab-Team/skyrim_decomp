// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GRefCountImpl.h; MIT.
// GRefCountImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GRefCountImplLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/scaleform/GRefCountImplLayout.h.
// GRefCountImplStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "GRefCountImplCoreStorageLayout.h"

namespace ResearchLayouts {
class GRefCountImplStorageLayout : public GRefCountImplCoreStorageLayout {
public:
    virtual ~GRefCountImplStorageLayout();
};
static_assert(sizeof(GRefCountImplStorageLayout) == 16, "community represented size");
}
