// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraDetachTime.h; MIT.
// ExtraDetachTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDetachTimeLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraDetachTimeLayout.h.
// ExtraDetachTimeStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraDetachTimeStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraDetachTimeStorageLayout();
    std::uint32_t time;
};
static_assert(sizeof(ExtraDetachTimeStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraDetachTimeStorageLayout, time) == 16, "time offset");
}
