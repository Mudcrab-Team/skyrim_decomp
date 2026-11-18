// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiExtraData.h; MIT.
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiExtraDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiExtraDataLayout.h.
// NiExtraDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringStorageLayout.h"
#include "NiObjectStorageLayout.h"

namespace ResearchLayouts {
class NiExtraDataStorageLayout : public NiObjectStorageLayout {
public:
    virtual ~NiExtraDataStorageLayout();
    BSFixedStringStorageLayout name;
};
static_assert(sizeof(NiExtraDataStorageLayout) == 24, "community represented size");
static_assert(offsetof(NiExtraDataStorageLayout, name) == 16, "name offset");
}
