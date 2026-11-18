// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraDistantData.h; MIT.
// ExtraDistantData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDistantDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraDistantDataLayout.h.
// ExtraDistantDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"
#include "BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class ExtraDistantDataStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraDistantDataStorageLayout();
    NiPoint3StorageLayout landNormal;
};
static_assert(sizeof(ExtraDistantDataStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraDistantDataStorageLayout, landNormal) == 16, "landNormal offset");
}
