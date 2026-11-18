// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiAllocator::~NiAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class NiAllocator
{
public:
    NiAllocator();
    virtual ~NiAllocator();  // compared: 0xeae960 (scalar deleting destructor)
};
static_assert(sizeof(NiAllocator) == 0x8, "NiAllocator size");
