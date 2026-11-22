// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESFile, TESNPC::FindInFileFast, TESNPC::fileOffset, TESNPC::formID, TESFile::OpenTES, TESFile::Seek, TESFile::GetFormType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what this unit uses; GetFormType is widened to 32 bits as the comparison is done on the whole register
// TESFile::currentFormID: GUESS(low); stands for NG's currentform.formID at 0x290
// TESNPC::FindInFileFast: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// g_npcFormType: GUESS(low); a byte global the form type is compared with
#pragma once

#include <cstdint>

extern const std::uint8_t g_npcFormType;

class TESFile
{
public:
    bool OpenTES(std::uint32_t accessMode, bool lock);
    bool Seek(std::uint32_t offset);
    std::uint32_t GetFormType();

    unsigned char pad000[0x290];
    std::uint32_t currentFormID;
};

class TESNPC
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual bool FindInFileFast(TESFile* file);

    unsigned char pad08[0xC];
    std::uint32_t formID;
    unsigned char pad18[0x1E0 - 0x18];
    std::uint32_t fileOffset;
};
