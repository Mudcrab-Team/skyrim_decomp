// Origin: copied represented declaration from reconstruction/netimmerse/NiObjectLayout.h; only include spellings changed.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiObject.h; MIT.
// NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObjectLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "NiRefObjectLayout.h"

namespace ResearchLayouts {
class NiObjectLayout : public NiRefObjectLayout {
public:
    virtual ~NiObjectLayout();
};
static_assert(sizeof(NiObjectLayout) == 16, "community represented size");
}
