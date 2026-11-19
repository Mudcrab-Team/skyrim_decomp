// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Script::InitItemImpl, Script::GetProcessScripts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::~Script, Script::SetProcessScripts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the deleting destructor at 0x346a60 and the static setter at 0x346390
// Script::unknown20, ::unknown28, ::unknown30, ::unknown38, ::unknown40, ::unknown48, ::unknown50, ::unknown58, ::unknown60, ::unknown68, ::unknown70, ::unknown78: GUESS(low); the class runs to 0x80 and no compared body here reads these
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"

class Script : public TESForm
{
public:
    Script();
    virtual ~Script();  // complete destructor at 0x342ac0, called by the compared deleting destructor at 0x346a60
    virtual void InitItemImpl();  // compared: 0x344760
    static bool GetProcessScripts();  // compared: 0x3463a0
    static void SetProcessScripts(bool a_set);  // compared: 0x346390

    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
};
static_assert(sizeof(Script) == 0x80, "Script size");
