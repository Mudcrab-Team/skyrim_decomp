// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// TESNPC, TESNPC::GetTextForParsedSubTag: CRASHLOGGER_PDB(59818@2026.10.24)
// TESForm, TESFullName, TESRace, BSFixedString, BGSLocalizedStringDL: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_subTag0, g_subTag1, g_subTag2, g_subTag3, g_subTag4, g_subTag5, g_subTag6, g_subTagRace, g_subTagShortName, g_maleText0, g_femaleText0, g_maleText1, g_femaleText1, g_maleText2, g_femaleText2, g_maleText3, g_femaleText3, g_maleText4, g_femaleText4, g_maleText5, g_femaleText5, g_maleText6, g_femaleText6, fullName, race, shortName, unk00, unkE0, unk160: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BSFixedString
{
public:
    const char* data;
};

class TESFullName
{
public:
    virtual ~TESFullName();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual const char* GetFullName() const;
};
static_assert(sizeof(TESFullName) == 0x08, "TESFullName size");

class BGSLocalizedStringDL
{
public:
    const char* GetString() const;

    std::uint32_t id;
};

class TESRace
{
public:
    const char* GetName() const;
};

class TESForm
{
public:
    const char* GetTextForParsedSubTag(const BSFixedString& a_tag) const;
};

extern const char* g_subTag0;
extern const char* g_subTag1;
extern const char* g_subTag2;
extern const char* g_subTag3;
extern const char* g_subTag4;
extern const char* g_subTag5;
extern const char* g_subTag6;
extern const char* g_subTagRace;
extern const char* g_subTagShortName;

extern const char* g_maleText0;
extern const char* g_femaleText0;
extern const char* g_maleText1;
extern const char* g_femaleText1;
extern const char* g_maleText2;
extern const char* g_femaleText2;
extern const char* g_maleText3;
extern const char* g_femaleText3;
extern const char* g_maleText4;
extern const char* g_femaleText4;
extern const char* g_maleText5;
extern const char* g_femaleText5;
extern const char* g_maleText6;
extern const char* g_femaleText6;

class TESNPC : public TESForm
{
public:
    std::int32_t GetSex() const;
    const char* GetTextForParsedSubTag(const BSFixedString& a_tag) const;

    const char* GetShortNameInline() const
    {
        const char* name = shortName.GetString();
        if (!name || *name == 0) {
            return fullName.GetFullName();
        }
        return name;
    }

    std::uint8_t unk00[0xD8];
    TESFullName fullName;
    std::uint8_t unkE0[0x158 - 0xE0];
    TESRace* race;
    std::uint8_t unk160[0x208 - 0x160];
    BGSLocalizedStringDL shortName;
};
static_assert(offsetof(TESNPC, fullName) == 0xD8, "TESNPC::fullName offset");
static_assert(offsetof(TESNPC, race) == 0x158, "TESNPC::race offset");
static_assert(offsetof(TESNPC, shortName) == 0x208, "TESNPC::shortName offset");
