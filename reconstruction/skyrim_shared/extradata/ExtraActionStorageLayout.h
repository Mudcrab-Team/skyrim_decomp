// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraAction.h; MIT.
// ExtraAction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraActionLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraActionLayout.h.
// ExtraActionStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class TESObjectREFR;
class ExtraActionStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraActionStorageLayout();
    std::int8_t action;
    TESObjectREFR* actionRef;
};
static_assert(sizeof(ExtraActionStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraActionStorageLayout, action) == 16, "action offset");
static_assert(offsetof(ExtraActionStorageLayout, actionRef) == 24, "actionRef offset");
}
