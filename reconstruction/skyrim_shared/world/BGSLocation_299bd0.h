// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLocation: EXE_RTTI
// BGSLocation::sub_1402427F0: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSLocation::parentLoc, BGSKeywordForm, BGSKeywordForm::HasKeyword, BGSKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLocation::unk00, BGSKeywordForm::Unk_01, BGSKeywordForm::Unk_02, BGSKeywordForm::Unk_03, BGSKeywordForm::unk08, BGSLocationBase: GUESS(low); base layout and virtual slot observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class BGSKeyword;

class BGSLocationBase
{
public:
    virtual ~BGSLocationBase();  // 00

    std::uint8_t unk08[0x28];  // 08
};
static_assert(sizeof(BGSLocationBase) == 0x30, "BGSLocationBase size");

class BGSKeywordForm
{
public:
    virtual ~BGSKeywordForm();                             // 00
    virtual void Unk_01();                                 // 01
    virtual void Unk_02();                                 // 02
    virtual void Unk_03();                                 // 03
    virtual bool HasKeyword(const BGSKeyword* a_kywd) const;  // 04

    std::uint8_t unk08[0x10];  // 08
};
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");

class BGSLocation : public BGSLocationBase, public BGSKeywordForm
{
public:
    BGSLocation* sub_1402427F0(const BGSKeyword* a_keyword);

    BGSLocation* parentLoc;  // 48
};
static_assert(offsetof(BGSLocation, parentLoc) == 0x48, "BGSLocation::parentLoc offset");
