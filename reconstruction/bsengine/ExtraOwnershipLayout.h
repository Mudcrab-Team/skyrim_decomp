// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraOwnership.h; MIT.
// ExtraOwnership: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraOwnershipLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESForm;
class ExtraOwnershipLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraOwnershipLayout();
    TESForm* owner;
};
static_assert(sizeof(ExtraOwnershipLayout) == 24, "community represented size");
static_assert(offsetof(ExtraOwnershipLayout, owner) == 16, "owner offset");
}
