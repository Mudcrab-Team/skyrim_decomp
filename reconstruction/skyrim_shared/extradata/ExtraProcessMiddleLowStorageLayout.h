// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraProcessMiddleLow.h; MIT.
// ExtraProcessMiddleLow: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraProcessMiddleLowLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraProcessMiddleLowLayout.h.
// ExtraProcessMiddleLowStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraProcessMiddleLowStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraProcessMiddleLowStorageLayout();
    std::uint32_t refCount;
};
static_assert(sizeof(ExtraProcessMiddleLowStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraProcessMiddleLowStorageLayout, refCount) == 16, "refCount offset");
}
