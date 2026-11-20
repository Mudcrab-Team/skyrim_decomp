// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiProperty.h; MIT.
// NiProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPropertyLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiPropertyLayout.h.
// NiPropertyStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "NiObjectNETStorageLayout.h"

namespace ResearchLayouts {
class NiPropertyStorageLayout : public NiObjectNETStorageLayout {
public:
    virtual ~NiPropertyStorageLayout();
};
static_assert(sizeof(NiPropertyStorageLayout) == 48, "community represented size");
}
