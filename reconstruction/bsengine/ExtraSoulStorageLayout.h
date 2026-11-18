// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraSoul.h; MIT.
// ExtraSoul: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraSoulLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraSoulLayout.h.
// ExtraSoulStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraSoulStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraSoulStorageLayout();
    std::uint8_t soul;
};
static_assert(sizeof(ExtraSoulStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraSoulStorageLayout, soul) == 16, "soul offset");
}
