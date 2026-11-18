// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCount.h; MIT.
// ExtraCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCountLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraCountLayout.h.
// ExtraCountStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraCountStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraCountStorageLayout();
    std::int16_t count;
};
static_assert(sizeof(ExtraCountStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraCountStorageLayout, count) == 16, "count offset");
}
