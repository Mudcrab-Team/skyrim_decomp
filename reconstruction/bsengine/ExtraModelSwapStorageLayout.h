// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraModelSwap.h; MIT.
// ExtraModelSwap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraModelSwapLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraModelSwapLayout.h.
// ExtraModelSwapStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class TESForm;
class TESModel;
class ExtraModelSwapStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraModelSwapStorageLayout();
    TESModel* modelSwap;
    TESForm* modelSwapForm;
};
static_assert(sizeof(ExtraModelSwapStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraModelSwapStorageLayout, modelSwap) == 16, "modelSwap offset");
static_assert(offsetof(ExtraModelSwapStorageLayout, modelSwapForm) == 24, "modelSwapForm offset");
}
