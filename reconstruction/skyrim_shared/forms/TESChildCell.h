// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESChildCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESChildCell::~TESChildCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class TESChildCell
{
public:
    TESChildCell();
    virtual ~TESChildCell();  // compared: 0x2b6290 (scalar deleting destructor)
};
static_assert(sizeof(TESChildCell) == 0x8, "TESChildCell size");
