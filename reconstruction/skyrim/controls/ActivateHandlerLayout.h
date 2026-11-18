// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActivateHandler.h; MIT.
// ActivateHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActivateHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/controls/HeldStateHandlerLayout.h"

namespace ResearchLayouts {
class ActivateHandlerLayout : public HeldStateHandlerLayout {
public:
    virtual ~ActivateHandlerLayout();
    std::uint8_t unk18;
    std::uint8_t unk19;
    bool heldButtonActionSuccess;
    bool disabled;
    std::uint32_t unk1C;
};
static_assert(sizeof(ActivateHandlerLayout) == 32, "community represented size");
static_assert(offsetof(ActivateHandlerLayout, unk18) == 24, "unk18 offset");
static_assert(offsetof(ActivateHandlerLayout, unk19) == 25, "unk19 offset");
static_assert(offsetof(ActivateHandlerLayout, heldButtonActionSuccess) == 26, "heldButtonActionSuccess offset");
static_assert(offsetof(ActivateHandlerLayout, disabled) == 27, "disabled offset");
static_assert(offsetof(ActivateHandlerLayout, unk1C) == 28, "unk1C offset");
}
