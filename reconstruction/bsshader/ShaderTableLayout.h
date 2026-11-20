// Source exposure: mixed (community declarations and local RTTI analysis).
// Declaration source: include/RE/B/BSTHashMap.h
// BSTScatterTable, BSTScatterTableHeapAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderTableLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
struct ShaderTableLayout {
    std::uint64_t reserved00;
    std::uint32_t reserved08;
    std::uint32_t capacity;
    std::uint32_t free;
    std::uint32_t good;
    const void* sentinel;
    std::uint64_t allocatorReserved;
    void* entries;
};
static_assert(sizeof(ShaderTableLayout) == 48, "scatter table storage");
}
