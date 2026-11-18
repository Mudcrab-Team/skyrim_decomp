// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/P/PlayerInputHandler.h; MIT.
// PlayerInputHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerInputHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class PlayerInputHandlerLayout {
public:
    virtual ~PlayerInputHandlerLayout();
    bool inputEventHandlingEnabled;
};
static_assert(sizeof(PlayerInputHandlerLayout) == 16, "community represented size");
static_assert(offsetof(PlayerInputHandlerLayout, inputEventHandlingEnabled) == 8, "inputEventHandlingEnabled offset");
}
