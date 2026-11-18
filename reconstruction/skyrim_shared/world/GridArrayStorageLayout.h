// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GridArray.h; MIT.
// GridArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GridArrayLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/GridArrayLayout.h.
// GridArrayStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class GridArrayStorageLayout {
public:
    virtual ~GridArrayStorageLayout();
    std::uint32_t unk08;
    std::uint32_t unk0C;
    std::uint32_t length;
};
static_assert(sizeof(GridArrayStorageLayout) == 24, "community represented size");
static_assert(offsetof(GridArrayStorageLayout, unk08) == 8, "unk08 offset");
static_assert(offsetof(GridArrayStorageLayout, unk0C) == 12, "unk0C offset");
static_assert(offsetof(GridArrayStorageLayout, length) == 16, "length offset");
}
