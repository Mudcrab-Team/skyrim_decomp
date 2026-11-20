// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraHotkey.h; MIT.
// ExtraHotkey: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraHotkeyLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraHotkeyLayout.h.
// ExtraHotkeyStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraHotkeyStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraHotkeyStorageLayout();
    std::uint8_t hotkey;
    std::uint8_t unk11;
    std::uint16_t unk12;
    std::uint32_t unk14;
};
static_assert(sizeof(ExtraHotkeyStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraHotkeyStorageLayout, hotkey) == 16, "hotkey offset");
static_assert(offsetof(ExtraHotkeyStorageLayout, unk11) == 17, "unk11 offset");
static_assert(offsetof(ExtraHotkeyStorageLayout, unk12) == 18, "unk12 offset");
static_assert(offsetof(ExtraHotkeyStorageLayout, unk14) == 20, "unk14 offset");
}
