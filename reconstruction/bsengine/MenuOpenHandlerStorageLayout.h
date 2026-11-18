// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MenuOpenHandler.h; MIT.
// MenuOpenHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MenuOpenHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/MenuOpenHandlerLayout.h.
// MenuOpenHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "MenuEventHandlerStorageLayout.h"

namespace ResearchLayouts {
class MenuOpenHandlerStorageLayout : public MenuEventHandlerStorageLayout {
public:
    virtual ~MenuOpenHandlerStorageLayout();
    bool unk10;
    std::uint8_t unk11;
    std::uint16_t unk12;
    std::uint32_t unk14;
};
static_assert(sizeof(MenuOpenHandlerStorageLayout) == 24, "community represented size");
static_assert(offsetof(MenuOpenHandlerStorageLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(MenuOpenHandlerStorageLayout, unk11) == 17, "unk11 offset");
static_assert(offsetof(MenuOpenHandlerStorageLayout, unk12) == 18, "unk12 offset");
static_assert(offsetof(MenuOpenHandlerStorageLayout, unk14) == 20, "unk14 offset");
}
