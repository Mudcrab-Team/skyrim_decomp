// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWindModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSWindModifier::GetRTTI, BSWindModifier::~BSWindModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRTTI: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
// Unit-local view of BSWindModifier: carries the members and declarations the functions of this unit need, so the shared BSWindModifier.h stays as it is.
#pragma once

#include <cstdint>
#include <cstddef>
#include "../niparticle/NiPSysModifier.h"

class NiRTTI;

class BSWindModifier : public NiPSysModifier
{
public:
    BSWindModifier();
    void LoadBinary(NiStream& a_stream) override;  // compared: 0xfd8bd0
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xfd8f90
    virtual ~BSWindModifier();  // compared: 0xfd8f50 (scalar deleting destructor)

    // fStrength: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); the float at 0x30
    float fStrength;               // 30
    std::uint8_t unknown34[0x4];   // 34
};
static_assert(sizeof(BSWindModifier) == 0x38, "BSWindModifier size");
