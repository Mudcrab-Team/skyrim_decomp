// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm: EXE_RTTI
// TESForm::GetGoldValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ConstructibleObject, ConstructibleObject::GetSkillAdvanceAmount, ConstructibleObject::unk00, ConstructibleObject::createdItem, ConstructibleObject::unk48, ConstructibleObject::createdCount, g_constructSkillExp, g_constructSkillMult, g_constructSkillOffset: GUESS(low) STANDIN
// TESForm::GetConstructedObjectSkillAdvancAmount_1403C1120: GUESS(low); CrashLogger PDB (59818@2026.10.24) attaches this name to TESForm, but offsets 0x40 and 0x50 belong to a constructible-object layout
#pragma once

#include <cstddef>
#include <cstdint>

extern float g_constructSkillExp;
extern float g_constructSkillMult;
extern float g_constructSkillOffset;

class TESForm
{
public:
    std::int32_t GetGoldValue() const;
};

class ConstructibleObject
{
public:
    float GetSkillAdvanceAmount() const;

    std::uint8_t  unk00[0x40];   // 00
    TESForm*      createdItem;   // 40
    std::uint64_t unk48;         // 48
    std::uint16_t createdCount;  // 50
};
static_assert(offsetof(ConstructibleObject, createdItem) == 0x40, "createdItem offset");
static_assert(offsetof(ConstructibleObject, createdCount) == 0x50, "createdCount offset");
