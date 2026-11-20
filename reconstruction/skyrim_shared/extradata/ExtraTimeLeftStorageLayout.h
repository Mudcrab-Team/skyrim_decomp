// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraTimeLeft.h; MIT.
// ExtraTimeLeft: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraTimeLeftLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraTimeLeftLayout.h.
// ExtraTimeLeftStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraTimeLeftStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraTimeLeftStorageLayout();
    float time;
};
static_assert(sizeof(ExtraTimeLeftStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraTimeLeftStorageLayout, time) == 16, "time offset");
}
