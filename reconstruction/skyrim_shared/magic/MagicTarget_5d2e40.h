// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// MagicTarget::GetTargetStatsObject, MagicTarget::IsInvulnerable, MagicTarget::MagicTargetIsActor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
// MagicTarget::GetMagicTargetFormID: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// MagicTarget::unk00, ::unk01: GUESS(low); placeholder slots so the declared slots land at 02 and 03, never defined
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR {
public:
    std::uint8_t  unk00[0x14];  // 00
    std::uint32_t formID;       // 14
};

class MagicTarget
{
public:
    virtual void unk00();  // 00
    virtual void unk01();  // 01
    virtual TESObjectREFR* GetTargetStatsObject();  // 02  // compared: 0x17ee10
    virtual bool MagicTargetIsActor() const;  // 03; compared: 0x17eea0
    virtual bool IsInvulnerable();  // compared: 0x17ee30
    std::uint32_t GetMagicTargetFormID();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x10];  // 08
};
static_assert(sizeof(MagicTarget) == 0x18, "MagicTarget size");
