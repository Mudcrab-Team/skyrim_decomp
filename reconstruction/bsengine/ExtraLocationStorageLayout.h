// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraLocation.h; MIT.
// ExtraLocation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraLocationLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraLocationLayout.h.
// ExtraLocationStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class BGSLocation;
class ExtraLocationStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraLocationStorageLayout();
    BGSLocation* location;
};
static_assert(sizeof(ExtraLocationStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraLocationStorageLayout, location) == 16, "location offset");
}
