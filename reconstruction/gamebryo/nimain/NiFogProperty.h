// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFogProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiProperty: STANDIN EXE_RTTI
// NiFogProperty::~NiFogProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include "NiObjectNET.h"

class NiProperty : public NiObjectNET
{
public:
};
static_assert(sizeof(NiProperty) == 0x30, "NiProperty size");

class NiFogProperty : public NiProperty
{
public:
    NiFogProperty();
    virtual ~NiFogProperty();  // compared: 0xf11f90 (scalar deleting destructor); declared only, rule 18

    std::uint8_t unknown30[0x20];  // 30
};
static_assert(sizeof(NiFogProperty) == 0x50, "NiFogProperty size");
