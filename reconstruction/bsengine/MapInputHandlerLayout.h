// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MapInputHandler.h; MIT.
// MapInputHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MapInputHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/MenuEventHandlerLayout.h"

namespace ResearchLayouts {
class MapMenu;
class MapInputHandlerLayout : public MenuEventHandlerLayout {
public:
    virtual ~MapInputHandlerLayout();
    MapMenu* mapMenu;
};
static_assert(sizeof(MapInputHandlerLayout) == 24, "community represented size");
static_assert(offsetof(MapInputHandlerLayout, mapMenu) == 16, "mapMenu offset");
}
