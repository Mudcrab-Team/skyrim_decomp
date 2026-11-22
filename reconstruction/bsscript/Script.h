// Code origin: original declarations with the labelled community layouts and member names.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Script::InitItemImpl, Script::GetProcessScripts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::profilerTimer: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"

class Script : public TESForm
{
public:
    virtual void InitItemImpl();  // compared: 0x344760
    static bool GetProcessScripts();  // compared: 0x3463a0
    std::uint8_t unknown20[0x28];  // 20
    float profilerTimer;          // 48
};

std::uint32_t ClearProfilerTimersFunctor(Script& a_script);
