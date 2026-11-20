// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraFromAlias.h; MIT.
// ExtraFromAlias: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraFromAliasLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraFromAliasLayout.h.
// ExtraFromAliasStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class TESQuest;
class ExtraFromAliasStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraFromAliasStorageLayout();
    TESQuest* quest;
    std::uint32_t aliasID;
};
static_assert(sizeof(ExtraFromAliasStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraFromAliasStorageLayout, quest) == 16, "quest offset");
static_assert(offsetof(ExtraFromAliasStorageLayout, aliasID) == 24, "aliasID offset");
}
