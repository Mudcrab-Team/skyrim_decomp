// Origin: copied represented declaration from reconstruction/netimmerse/NiPropertyLayout.h; only include spellings changed.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiProperty.h; MIT.
// NiProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPropertyLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "NiObjectNETLayout.h"

namespace ResearchLayouts {
class NiPropertyLayout : public NiObjectNETLayout {
public:
    virtual ~NiPropertyLayout();
};
static_assert(sizeof(NiPropertyLayout) == 48, "community represented size");
}
