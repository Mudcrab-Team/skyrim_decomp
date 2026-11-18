// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraAction.h; MIT.
// ExtraAction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraActionLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESObjectREFR;
class ExtraActionLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraActionLayout();
    std::int8_t action;
    TESObjectREFR* actionRef;
};
static_assert(sizeof(ExtraActionLayout) == 32, "community represented size");
static_assert(offsetof(ExtraActionLayout, action) == 16, "action offset");
static_assert(offsetof(ExtraActionLayout, actionRef) == 24, "actionRef offset");
}
