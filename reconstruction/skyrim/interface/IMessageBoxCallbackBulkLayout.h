// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IMessageBoxCallback.h; MIT.
// IMessageBoxCallback: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMessageBoxCallbackLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/IMessageBoxCallbackLayout.h.
// IMessageBoxCallbackStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
// Code origin: declarations adapted from the pinned represented community header; no implementation bodies reused.
// IMessageBoxCallbackBulkLayout, BSIntrusiveRefCountedBulkLayout: GUESS(medium) STANDIN; represented layout aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSIntrusiveRefCountedBulkLayout.h"

namespace ResearchLayouts {
class IMessageBoxCallbackBulkLayout : public BSIntrusiveRefCountedBulkLayout {
public:
    virtual ~IMessageBoxCallbackBulkLayout();
    std::uint32_t unk0C;
};
static_assert(sizeof(IMessageBoxCallbackBulkLayout) == 16, "community represented size");
static_assert(offsetof(IMessageBoxCallbackBulkLayout, unk0C) == 12, "unk0C offset");
}
