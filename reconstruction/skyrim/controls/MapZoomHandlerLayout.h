// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MapZoomHandler.h; MIT.
// MapZoomHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MapZoomHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/controls/MapInputHandlerLayout.h"

namespace ResearchLayouts {
class MapZoomHandlerLayout : public MapInputHandlerLayout {
public:
    virtual ~MapZoomHandlerLayout();
};
static_assert(sizeof(MapZoomHandlerLayout) == 24, "community represented size");
}
