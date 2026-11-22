// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0xfda6e0 compared function
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
    // BSPortalGraph::Functionfda6e0: GUESS(low); reads the word at 0x68
    std::uint32_t Functionfda6e0() const;

    // member: GUESS(low); storage at the offset the compared getter reads
    std::uint8_t pad10[0x58];  // 10
    std::uint32_t member68;    // 68
    std::uint8_t pad6C[0x5C];  // 6C
};
static_assert(sizeof(BSPortalGraph) == 0xC8, "BSPortalGraph size");
