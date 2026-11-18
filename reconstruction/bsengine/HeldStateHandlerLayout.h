// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/H/HeldStateHandler.h; MIT.
// HeldStateHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HeldStateHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "actors/PlayerInputHandlerLayout.h"

namespace ResearchLayouts {
class HeldStateHandlerLayout : public PlayerInputHandlerLayout {
public:
    virtual ~HeldStateHandlerLayout();
    bool heldStateActive;
    bool triggerReleaseEvent;
};
static_assert(sizeof(HeldStateHandlerLayout) == 24, "community represented size");
static_assert(offsetof(HeldStateHandlerLayout, heldStateActive) == 16, "heldStateActive offset");
static_assert(offsetof(HeldStateHandlerLayout, triggerReleaseEvent) == 17, "triggerReleaseEvent offset");
}
