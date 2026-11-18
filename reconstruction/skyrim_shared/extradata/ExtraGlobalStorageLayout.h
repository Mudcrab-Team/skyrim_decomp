// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraGlobal.h; MIT.
// ExtraGlobal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraGlobalLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraGlobalLayout.h.
// ExtraGlobalStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class TESGlobal;
class ExtraGlobalStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraGlobalStorageLayout();
    TESGlobal* global;
};
static_assert(sizeof(ExtraGlobalStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraGlobalStorageLayout, global) == 16, "global offset");
}
