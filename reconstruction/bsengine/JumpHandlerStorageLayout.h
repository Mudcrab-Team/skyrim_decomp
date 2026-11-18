// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/J/JumpHandler.h; MIT.
// JumpHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// JumpHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/JumpHandlerLayout.h.
// JumpHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../actors/PlayerInputHandlerStorageLayout.h"

namespace ResearchLayouts {
class JumpHandlerStorageLayout : public PlayerInputHandlerStorageLayout {
public:
    virtual ~JumpHandlerStorageLayout();
};
static_assert(sizeof(JumpHandlerStorageLayout) == 16, "community represented size");
}
