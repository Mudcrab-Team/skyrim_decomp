// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MapInputHandler.h; MIT.
// MapInputHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MapInputHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/MapInputHandlerLayout.h.
// MapInputHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "MenuEventHandlerStorageLayout.h"

namespace ResearchLayouts {
class MapMenu;
class MapInputHandlerStorageLayout : public MenuEventHandlerStorageLayout {
public:
    virtual ~MapInputHandlerStorageLayout();
    MapMenu* mapMenu;
};
static_assert(sizeof(MapInputHandlerStorageLayout) == 24, "community represented size");
static_assert(offsetof(MapInputHandlerStorageLayout, mapMenu) == 16, "mapMenu offset");
}
