// Source exposure: mixed (community declarations and target copy/construction/RTTI analysis).
// Code origin: original empty destructor stand-ins using independently represented fields; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/StreamBase.h and include/RE/A/AsyncStream.h; MIT.
// StreamBase, AsyncStream, totalSize, flags, minPacketSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ResourceStreamBaseLayout, ResourceAsyncStreamLayout: GUESS(medium) STANDIN
// object: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
class ResourceStreamBaseLayout {
public:
    virtual ~ResourceStreamBaseLayout() {}
    std::uint64_t totalSize;
    std::uint32_t flags;
};
static_assert(sizeof(ResourceStreamBaseLayout) == 24, "represented resource stream base");
static_assert(offsetof(ResourceStreamBaseLayout, totalSize) == 8, "observed target qword field");
static_assert(offsetof(ResourceStreamBaseLayout, flags) == 16, "observed target flags");
}
