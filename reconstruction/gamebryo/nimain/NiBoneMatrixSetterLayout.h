// Source exposure: mixed (community declarations and local RTTI analysis).
// Declaration source: include/RE/N/NiBoneMatrixSetterI.h
// NiBoneMatrixSetterI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBoneMatrixSetterLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
class NiBoneMatrixSetterLayout {
public:
    virtual ~NiBoneMatrixSetterLayout();
};
static_assert(sizeof(NiBoneMatrixSetterLayout) == 8, "matrix interface size");
}
