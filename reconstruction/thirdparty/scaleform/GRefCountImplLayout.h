// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GRefCountImpl.h; MIT.
// GRefCountImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GRefCountImplLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "thirdparty/scaleform/GRefCountImplCoreLayout.h"

namespace ResearchLayouts {
class GRefCountImplLayout : public GRefCountImplCoreLayout {
public:
    virtual ~GRefCountImplLayout();
};
static_assert(sizeof(GRefCountImplLayout) == 16, "community represented size");
}
