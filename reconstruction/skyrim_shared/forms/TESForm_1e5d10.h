// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESForm: EXE_RTTI
// TESForm::GetFormDetailedString_1401947A0: CRASHLOGGER_PDB(59818@2026.10.24)
// TESForm::formID, TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm::unk00, TESForm::unk18, FormTypeNameEntry, FormTypeNameEntry::name, FormTypeNameEntry::unk08, g_formTypeNames, g_formDetailedFormat, g_emptyString, FormatString: GUESS(low); offsets, globals, and call observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

struct FormTypeNameEntry
{
    const char*   name;     // 00
    std::uint64_t unk08[2]; // 08
};
static_assert(sizeof(FormTypeNameEntry) == 0x18, "FormTypeNameEntry size");

extern FormTypeNameEntry g_formTypeNames[];
extern const char g_formDetailedFormat[];
extern const char g_emptyString[];

std::int32_t FormatString(char* a_buf, std::size_t a_size, const char* a_fmt, ...);

class TESForm
{
public:
    virtual void GetFormDetailedString_1401947A0(char* a_buf, std::uint32_t a_bufLen);

    std::uint8_t  unk00[0xC];  // 08
    std::uint32_t formID;      // 14
    std::uint16_t unk18;       // 18
    std::uint8_t  formType;    // 1A
};
static_assert(offsetof(TESForm, formID) == 0x14, "TESForm::formID offset");
static_assert(offsetof(TESForm, formType) == 0x1A, "TESForm::formType offset");
