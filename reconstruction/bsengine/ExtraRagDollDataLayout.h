// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRagDollData.h; MIT.
// ExtraRagDollData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRagDollDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class RagDollData;
class ExtraRagDollDataLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraRagDollDataLayout();
    RagDollData* ragDollData;
};
static_assert(sizeof(ExtraRagDollDataLayout) == 24, "community represented size");
static_assert(offsetof(ExtraRagDollDataLayout, ragDollData) == 16, "ragDollData offset");
}
