// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// MagicItemTraversalFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// MagicItemTraversalFunctor::~MagicItemTraversalFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class MagicItemTraversalFunctor
{
public:
    MagicItemTraversalFunctor();
    virtual ~MagicItemTraversalFunctor();  // compared: 0x1527c0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(MagicItemTraversalFunctor) == 0x10, "MagicItemTraversalFunctor size");
