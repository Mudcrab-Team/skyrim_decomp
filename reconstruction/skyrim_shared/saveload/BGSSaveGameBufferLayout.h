// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSSaveGameBuffer.h; MIT.
// BGSSaveGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSaveGameBufferLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BGSSaveGameBufferLayout {
public:
    virtual ~BGSSaveGameBufferLayout();
    void* buffer;
    std::uint32_t size;
    std::uint32_t bufferPosition;
};
static_assert(sizeof(BGSSaveGameBufferLayout) == 24, "community represented size");
static_assert(offsetof(BGSSaveGameBufferLayout, buffer) == 8, "buffer offset");
static_assert(offsetof(BGSSaveGameBufferLayout, size) == 16, "size offset");
static_assert(offsetof(BGSSaveGameBufferLayout, bufferPosition) == 20, "bufferPosition offset");
}
