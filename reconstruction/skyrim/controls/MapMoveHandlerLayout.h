// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MapMoveHandler.h; MIT.
// MapMoveHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MapMoveHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/controls/MapInputHandlerLayout.h"

namespace ResearchLayouts {
class MapMoveHandlerLayout : public MapInputHandlerLayout {
public:
    virtual ~MapMoveHandlerLayout();
    std::uint64_t unk18;
};
static_assert(sizeof(MapMoveHandlerLayout) == 32, "community represented size");
static_assert(offsetof(MapMoveHandlerLayout, unk18) == 24, "unk18 offset");
}
