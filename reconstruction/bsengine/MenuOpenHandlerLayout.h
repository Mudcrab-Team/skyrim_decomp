// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MenuOpenHandler.h; MIT.
// MenuOpenHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MenuOpenHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/MenuEventHandlerLayout.h"

namespace ResearchLayouts {
class MenuOpenHandlerLayout : public MenuEventHandlerLayout {
public:
    virtual ~MenuOpenHandlerLayout();
    bool unk10;
    std::uint8_t unk11;
    std::uint16_t unk12;
    std::uint32_t unk14;
};
static_assert(sizeof(MenuOpenHandlerLayout) == 24, "community represented size");
static_assert(offsetof(MenuOpenHandlerLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(MenuOpenHandlerLayout, unk11) == 17, "unk11 offset");
static_assert(offsetof(MenuOpenHandlerLayout, unk12) == 18, "unk12 offset");
static_assert(offsetof(MenuOpenHandlerLayout, unk14) == 20, "unk14 offset");
}
