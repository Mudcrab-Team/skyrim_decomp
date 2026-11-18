// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraSound.h; MIT.
// ExtraSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraSoundLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraSoundLayout.h.
// ExtraSoundStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"
#include "BSSoundHandleStorageLayout.h"

namespace ResearchLayouts {
class ExtraSoundStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraSoundStorageLayout();
    BSSoundHandleStorageLayout handle;
};
static_assert(sizeof(ExtraSoundStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraSoundStorageLayout, handle) == 16, "handle offset");
}
