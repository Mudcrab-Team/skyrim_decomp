// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraFromAlias.h; MIT.
// ExtraFromAlias: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraFromAliasLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESQuest;
class ExtraFromAliasLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraFromAliasLayout();
    TESQuest* quest;
    std::uint32_t aliasID;
};
static_assert(sizeof(ExtraFromAliasLayout) == 32, "community represented size");
static_assert(offsetof(ExtraFromAliasLayout, quest) == 16, "quest offset");
static_assert(offsetof(ExtraFromAliasLayout, aliasID) == 24, "aliasID offset");
}
