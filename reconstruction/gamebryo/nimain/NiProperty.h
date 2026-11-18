// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiProperty::~NiProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "NiObjectNET.h"

class NiProperty : public NiObjectNET
{
public:
    NiProperty();
    virtual ~NiProperty();  // compared: 0x20b410 (scalar deleting destructor); declared only, rule 18
};
static_assert(sizeof(NiProperty) == 0x30, "NiProperty size");
