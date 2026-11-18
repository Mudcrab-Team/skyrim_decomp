// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/ScreenshotHandler.h; MIT.
// ScreenshotHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ScreenshotHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/interface/MenuEventHandlerLayout.h"

namespace ResearchLayouts {
class ScreenshotHandlerLayout : public MenuEventHandlerLayout {
public:
    virtual ~ScreenshotHandlerLayout();
    bool screenshotQueued;
    bool multiScreenshotQueued;
};
static_assert(sizeof(ScreenshotHandlerLayout) == 24, "community represented size");
static_assert(offsetof(ScreenshotHandlerLayout, screenshotQueued) == 16, "screenshotQueued offset");
static_assert(offsetof(ScreenshotHandlerLayout, multiScreenshotQueued) == 17, "multiScreenshotQueued offset");
}
