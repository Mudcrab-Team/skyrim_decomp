// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MenuEventHandler.h; MIT.
// MenuEventHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MenuEventHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/MenuEventHandlerLayout.h.
// MenuEventHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSIntrusiveRefCountedStorageLayout.h"

namespace ResearchLayouts {
class MenuEventHandlerStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~MenuEventHandlerStorageLayout();
    bool registered;
    std::uint8_t unk0D;
};
static_assert(sizeof(MenuEventHandlerStorageLayout) == 16, "community represented size");
static_assert(offsetof(MenuEventHandlerStorageLayout, registered) == 12, "registered offset");
static_assert(offsetof(MenuEventHandlerStorageLayout, unk0D) == 13, "unk0D offset");
}
