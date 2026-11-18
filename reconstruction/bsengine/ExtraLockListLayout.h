// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraLockList.h; MIT.
// ExtraLockList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraLockListLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESForm;
class ExtraLockListLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraLockListLayout();
    TESForm* list;
};
static_assert(sizeof(ExtraLockListLayout) == 24, "community represented size");
static_assert(offsetof(ExtraLockListLayout, list) == 16, "list offset");
}
