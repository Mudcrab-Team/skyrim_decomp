// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraDecalGroup.h; MIT.
// ExtraDecalGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDecalGroupLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraDecalGroupLayout.h.
// ExtraDecalGroupStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class BGSDecalGroup;
class ExtraDecalGroupStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraDecalGroupStorageLayout();
    BGSDecalGroup* decalGroup;
};
static_assert(sizeof(ExtraDecalGroupStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraDecalGroupStorageLayout, decalGroup) == 16, "decalGroup offset");
}
