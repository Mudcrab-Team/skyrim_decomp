// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSSoundHandle.h; MIT.
// BSSoundHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSoundHandleLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSSoundHandleLayout {
public:
    std::uint32_t soundID;
    bool assumeSuccess;
    std::uint32_t state;
};
static_assert(sizeof(BSSoundHandleLayout) == 12, "community represented size");
static_assert(offsetof(BSSoundHandleLayout, soundID) == 0, "soundID offset");
static_assert(offsetof(BSSoundHandleLayout, assumeSuccess) == 4, "assumeSuccess offset");
static_assert(offsetof(BSSoundHandleLayout, state) == 8, "state offset");
}
