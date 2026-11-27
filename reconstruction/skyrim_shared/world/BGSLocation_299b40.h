// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLocation: EXE_RTTI
// BGSLocation::FindInFileFast_140242760, BGSLocation::fileOffset: CRASHLOGGER_PDB(59818@2026.10.24)
// TESFile, TESFile::Seek, TESFile::GetFormType, TESForm::formID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLocation::unk00, BGSLocation::formID, BGSLocation::unk18, TESFile::IsMaster, TESFile::unk000, TESFile::currentFormID: GUESS(low); offsets and calls observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile
{
public:
    bool          IsMaster() const;
    bool          Seek(std::uint32_t a_offset);
    std::uint32_t GetFormType();

    std::uint8_t  unk000[0x290];  // 000
    std::uint32_t currentFormID;  // 290
};
static_assert(offsetof(TESFile, currentFormID) == 0x290, "TESFile::currentFormID offset");

class BGSLocation
{
public:
    virtual bool FindInFileFast_140242760(TESFile* a_mod);

    std::uint8_t  unk00[0xC];   // 08
    std::uint32_t formID;       // 14
    std::uint8_t  unk18[0xB4];  // 18
    std::uint32_t fileOffset;   // CC
};
static_assert(offsetof(BGSLocation, formID) == 0x14, "BGSLocation::formID offset");
static_assert(offsetof(BGSLocation, fileOffset) == 0xCC, "BGSLocation::fileOffset offset");
