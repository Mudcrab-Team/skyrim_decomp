// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiExtraData.h; MIT.
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiExtraDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringLayout.h"
#include "netimmerse/NiObjectLayout.h"

namespace ResearchLayouts {
class NiExtraDataLayout : public NiObjectLayout {
public:
    virtual ~NiExtraDataLayout();
    BSFixedStringLayout name;
};
static_assert(sizeof(NiExtraDataLayout) == 24, "community represented size");
static_assert(offsetof(NiExtraDataLayout, name) == 16, "name offset");
}
