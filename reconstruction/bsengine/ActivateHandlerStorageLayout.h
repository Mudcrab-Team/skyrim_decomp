// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActivateHandler.h; MIT.
// ActivateHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActivateHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ActivateHandlerLayout.h.
// ActivateHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "HeldStateHandlerStorageLayout.h"

namespace ResearchLayouts {
class ActivateHandlerStorageLayout : public HeldStateHandlerStorageLayout {
public:
    virtual ~ActivateHandlerStorageLayout();
    std::uint8_t unk18;
    std::uint8_t unk19;
    bool heldButtonActionSuccess;
    bool disabled;
    std::uint32_t unk1C;
};
static_assert(sizeof(ActivateHandlerStorageLayout) == 32, "community represented size");
static_assert(offsetof(ActivateHandlerStorageLayout, unk18) == 24, "unk18 offset");
static_assert(offsetof(ActivateHandlerStorageLayout, unk19) == 25, "unk19 offset");
static_assert(offsetof(ActivateHandlerStorageLayout, heldButtonActionSuccess) == 26, "heldButtonActionSuccess offset");
static_assert(offsetof(ActivateHandlerStorageLayout, disabled) == 27, "disabled offset");
static_assert(offsetof(ActivateHandlerStorageLayout, unk1C) == 28, "unk1C offset");
}
