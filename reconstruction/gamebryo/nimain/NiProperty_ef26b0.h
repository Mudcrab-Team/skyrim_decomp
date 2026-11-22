// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiProperty::~NiProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "NiObjectNET.h"

class NiUpdateData;

class NiProperty : public NiObjectNET
{
public:
    NiProperty();
    // Update: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); a vtable slot in the image, declared here without virtual so the vtable stays as compared
    void Update(NiUpdateData& a_data);
    virtual ~NiProperty();  // compared: 0x20b410 (scalar deleting destructor); declared only, rule 18
};
static_assert(sizeof(NiProperty) == 0x30, "NiProperty size");
