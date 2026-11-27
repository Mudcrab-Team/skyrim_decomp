// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESQuest: EXE_RTTI
// TESQuest::SetKeepInstance: CRASHLOGGER_PDB(59818@2026.10.24)
// TESForm::AddChange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESQuest::Unk_01, TESQuest::Unk_02, TESQuest::Unk_03, TESQuest::Unk_04, TESQuest::Unk_05, TESQuest::Unk_06, TESQuest::Unk_07, TESQuest::Unk_08, TESQuest::Unk_09, TESQuest::AddChange, TESQuest::unk008, TESQuest::questFlags: GUESS(low); offsets and virtual slot observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESQuest
{
public:
    virtual ~TESQuest();                        // 00
    virtual void Unk_01();                      // 01
    virtual void Unk_02();                      // 02
    virtual void Unk_03();                      // 03
    virtual void Unk_04();                      // 04
    virtual void Unk_05();                      // 05
    virtual void Unk_06();                      // 06
    virtual void Unk_07();                      // 07
    virtual void Unk_08();                      // 08
    virtual void Unk_09();                      // 09
    virtual bool AddChange(std::uint32_t a_flags);  // 0A

    void SetKeepInstance(bool a_keep);

    std::uint8_t  unk008[0xD4];  // 008
    std::uint16_t questFlags;    // 0DC
};
static_assert(offsetof(TESQuest, questFlags) == 0xDC, "TESQuest::questFlags offset");
