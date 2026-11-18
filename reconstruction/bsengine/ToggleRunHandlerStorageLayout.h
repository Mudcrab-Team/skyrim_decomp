// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/ToggleRunHandler.h; MIT.
// ToggleRunHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ToggleRunHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ToggleRunHandlerLayout.h.
// ToggleRunHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../actors/PlayerInputHandlerStorageLayout.h"

namespace ResearchLayouts {
class ToggleRunHandlerStorageLayout : public PlayerInputHandlerStorageLayout {
public:
    virtual ~ToggleRunHandlerStorageLayout();
};
static_assert(sizeof(ToggleRunHandlerStorageLayout) == 16, "community represented size");
}
