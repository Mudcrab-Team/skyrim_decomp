// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiShadeProperty.h; MIT.
// NiShadeProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiShadePropertyLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "netimmerse/NiPropertyLayout.h"

namespace ResearchLayouts {
class NiShadePropertyLayout : public NiPropertyLayout {
public:
    virtual ~NiShadePropertyLayout();
};
static_assert(sizeof(NiShadePropertyLayout) == 48, "community represented size");
}
