// Source exposure: mixed (community declarations and local RTTI analysis).
// Declaration source: include/RE/N/NiRefObject.h
// NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderRefLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
class ShaderRefLayout {
public:
    virtual ~ShaderRefLayout();
    volatile std::uint32_t referenceCount;
};
static_assert(sizeof(ShaderRefLayout) == 16, "reference object size");
static_assert(offsetof(ShaderRefLayout, referenceCount) == 8, "reference counter offset");
}
