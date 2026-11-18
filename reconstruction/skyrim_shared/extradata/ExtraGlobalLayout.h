// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraGlobal.h; MIT.
// ExtraGlobal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraGlobalLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESGlobal;
class ExtraGlobalLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraGlobalLayout();
    TESGlobal* global;
};
static_assert(sizeof(ExtraGlobalLayout) == 24, "community represented size");
static_assert(offsetof(ExtraGlobalLayout, global) == 16, "global offset");
}
