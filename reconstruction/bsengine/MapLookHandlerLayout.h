// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MapLookHandler.h; MIT.
// MapLookHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MapLookHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/MapInputHandlerLayout.h"

namespace ResearchLayouts {
class MapLookHandlerLayout : public MapInputHandlerLayout {
public:
    virtual ~MapLookHandlerLayout();
    std::uint64_t unk18;
};
static_assert(sizeof(MapLookHandlerLayout) == 32, "community represented size");
static_assert(offsetof(MapLookHandlerLayout, unk18) == 24, "unk18 offset");
}
