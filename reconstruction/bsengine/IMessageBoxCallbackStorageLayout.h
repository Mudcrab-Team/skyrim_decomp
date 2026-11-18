// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IMessageBoxCallback.h; MIT.
// IMessageBoxCallback: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMessageBoxCallbackLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/IMessageBoxCallbackLayout.h.
// IMessageBoxCallbackStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSIntrusiveRefCountedStorageLayout.h"

namespace ResearchLayouts {
class IMessageBoxCallbackStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~IMessageBoxCallbackStorageLayout();
    std::uint32_t unk0C;
};
static_assert(sizeof(IMessageBoxCallbackStorageLayout) == 16, "community represented size");
static_assert(offsetof(IMessageBoxCallbackStorageLayout, unk0C) == 12, "unk0C offset");
}
