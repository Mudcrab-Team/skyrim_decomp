// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TogglePOVHandler.h; MIT.
// TogglePOVHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TogglePOVHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/TogglePOVHandlerLayout.h.
// TogglePOVHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "HeldStateHandlerStorageLayout.h"

namespace ResearchLayouts {
class TogglePOVHandlerStorageLayout : public HeldStateHandlerStorageLayout {
public:
    virtual ~TogglePOVHandlerStorageLayout();
    bool pressRegistered;
};
static_assert(sizeof(TogglePOVHandlerStorageLayout) == 32, "community represented size");
static_assert(offsetof(TogglePOVHandlerStorageLayout, pressRegistered) == 24, "pressRegistered offset");
}
