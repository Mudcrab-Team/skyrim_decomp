// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSceneAction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSceneAction::Unk_0B, BGSSceneAction::Unk_10, BGSSceneAction::ClearFlags, BGSSceneAction::Unk_11, BGSSceneAction::Unk_02: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>

class BGSSceneAction
{
public:
    virtual void Unk_0B();  // compared: 0x3ab090
    virtual void Unk_10();  // compared: 0x3ab120
    virtual void ClearFlags();  // compared: 0x3aaf60
    virtual void Unk_11();  // compared: 0x3ab130
    virtual void Unk_02(BGSSceneAction* a_other);  // compared: 0x3aaf20
    // Unk_05: GUESS(low)
    virtual bool Unk_05();

    // unknown08: GUESS(low)
    volatile std::uint32_t unknown08;  // 08
    std::uint32_t unknown0C;  // 0C
    // flags10: GUESS(low)
    std::uint32_t flags10;  // 10
    // flags14: GUESS(low)
    std::uint8_t flags14;  // 14
    std::uint8_t unknown15[0x83];  // 15
    // unknown98: GUESS(low)
    void* unknown98;  // 98
};
static_assert(sizeof(BGSSceneAction) == 0xA0, "BGSSceneAction size");

void* FindSceneActionEntry(void* a_table, std::uint32_t a_flags);
