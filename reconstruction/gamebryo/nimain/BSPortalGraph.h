// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPortalGraph: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSPortalGraph::~BSPortalGraph: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiRefObject.h"

class BSPortalGraph : public NiRefObject
{
public:
    BSPortalGraph();
    virtual ~BSPortalGraph();  // compared: 0xfdb1b0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0xB8];  // 10
};
static_assert(sizeof(BSPortalGraph) == 0xC8, "BSPortalGraph size");
