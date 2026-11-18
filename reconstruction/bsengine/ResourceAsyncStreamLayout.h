// Source exposure: mixed (community declarations and target copy/construction/RTTI analysis).
// Code origin: original empty destructor stand-ins using independently represented fields; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/StreamBase.h and include/RE/A/AsyncStream.h; MIT.
// StreamBase, AsyncStream, totalSize, flags, minPacketSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ResourceStreamBaseLayout, ResourceAsyncStreamLayout: GUESS(medium) STANDIN
// object: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "ResourceStreamBaseLayout.h"
namespace ResearchLayouts {
class ResourceAsyncStreamLayout : public ResourceStreamBaseLayout {
public:
    ~ResourceAsyncStreamLayout() override {}
    std::uint32_t minPacketSize;
};
static_assert(sizeof(ResourceAsyncStreamLayout) == 32, "represented async resource stream");
static_assert(offsetof(ResourceAsyncStreamLayout, minPacketSize) == 24, "observed target packet field");
}
