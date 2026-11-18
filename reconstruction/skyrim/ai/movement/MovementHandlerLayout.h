// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MovementHandler.h; MIT.
// MovementHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/controls/PlayerInputHandlerLayout.h"

namespace ResearchLayouts {
class MovementHandlerLayout : public PlayerInputHandlerLayout {
public:
    virtual ~MovementHandlerLayout();
};
static_assert(sizeof(MovementHandlerLayout) == 16, "community represented size");
}
