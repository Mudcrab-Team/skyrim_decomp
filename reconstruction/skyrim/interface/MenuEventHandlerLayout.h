// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MenuEventHandler.h; MIT.
// MenuEventHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MenuEventHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSIntrusiveRefCountedLayout.h"

namespace ResearchLayouts {
class MenuEventHandlerLayout : public BSIntrusiveRefCountedLayout {
public:
    virtual ~MenuEventHandlerLayout();
    bool registered;
    std::uint8_t unk0D;
};
static_assert(sizeof(MenuEventHandlerLayout) == 16, "community represented size");
static_assert(offsetof(MenuEventHandlerLayout, registered) == 12, "registered offset");
static_assert(offsetof(MenuEventHandlerLayout, unk0D) == 13, "unk0D offset");
}
