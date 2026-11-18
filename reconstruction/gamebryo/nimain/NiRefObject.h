// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiRefObject::~NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
// niRefObjectTotalCount: GUESS(low); the global count at RVA 0x331c620, bound by the unit's bind-hints.json
#pragma once

#include <cstdint>

extern "C" long niRefObjectTotalCount;

class NiRefObject
{
public:
    NiRefObject();
    virtual ~NiRefObject();  // compared: 0x213be0 (scalar deleting destructor)

    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");
